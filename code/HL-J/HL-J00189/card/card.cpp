#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int ans[300010],a[N];
vector<int>s;
bool find(vector<int>v,int x){
    for(int i=0;i<v.size();i++){
        if(v[i]==x){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(find(s,a[j])){
                while(s.back()!=a[j]){
                    s.pop_back();
                }

            }else{
                s.push_back(a[j]);
            }
        }
        while(!s.empty()){
            int p=s.back();
            ans[p]++;
            s.pop_back();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }




    return 0;
}
