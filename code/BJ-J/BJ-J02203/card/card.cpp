#include<bits/stdc++.h>
using namespace std;
int cnt[500005],flag[500005];
int n,m;
void game(vector<int> &v,int st){
    memset(flag,-1,sizeof(flag));
    vector<int> tmp;
    for(int i=st;i<v.size();i++){
        if(flag[v[i]]>=0){
            for(int j=flag[v[i]]+1;j<tmp.size();j++){
                flag[tmp[j]] = -1;
            }
            tmp.resize(flag[v[i]]+1);
        }
        else{
            flag[v[i]] = tmp.size();
            tmp.push_back(v[i]);
        }
    }
    for(int i=0;i<tmp.size();i++){
        cnt[tmp[i]]++;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    vector<int> v;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<n;i++){
        game(v,i);
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
}
