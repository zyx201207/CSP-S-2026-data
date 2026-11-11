#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);i++)
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N];
int ans[M];
map<int,int>mp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    For(i,1,n) cin>>a[i];
    if(n>5000){
        int a1=0,a2=0;
        For(i,1,n) if(a[i]!=a[n]) a1++,a2++;
        else if(a[n]==1) a1++;else a2++;
        cout<<a1<<' '<<a2;
        return 0;
    }
    For(i,1,n){
        For(j,i,n){
            if(mp[a[j]]){
                For(k,mp[a[j]],j) mp[a[k]]=0;
            }
            mp[a[j]]=j;
        }
        //For(j,i,n) cout<<mp[a[j]]<< ' ';
        //cout<<'\n';
        For(j,i,n)
            if(mp[a[j]]) ans[a[j]]++,mp[a[j]]=0;
        mp.clear();
    }
    For(i,1,m) cout<<ans[i]<<' ';
    return 0;
}
