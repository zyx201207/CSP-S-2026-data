#include<bits/stdc++.h>
using namespace std;

int n,m,cnt[500010];
int a[500010];
//bigmoni
//if(xx in xx)
int inv(int x,vector<int> k){
    if(k.size()==0) return -1;
    for(int i=0;i<k.size();i++){
        if(k[i]==x){
            return i;
        }
    }
    return -1;
}

//play
void play(int x){
    vector<int> v;
    for(int i=x;i<=n;i++){
        if(inv(a[i],v)!=-1){
            int o=v.size();
            for(int j=inv(a[i],v);j<=o-1;j++){
                //cout<<j<<endl<<endl;
                v.pop_back();
            }
        }
        v.push_back(a[i]);
    }
    for(int i=0;i<=v.size()-1;i++){
        //cout<<v[i]<<' ';
        cnt[v[i]]++;
    }
    //cout<<endl;
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int t=1;t<=n;t++){
        play(t);
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
