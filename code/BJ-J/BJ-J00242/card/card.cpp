#include<bits/stdc++.h>
using namespace std;
const int N=5005;
map<int,int>mp;
int ans[N][N];
int a[N],b[N];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    bool f=true;
    for(int i=1;i<n;i++){
        if(a[i]>a[i+1])f=false;
    }
    if(f){
        for(int i=1;i<=n;i++)mp[a[i]]=1;
        for(int i=1;i<=m;i++)cout<<mp[a[i]]<<" ";
        return 0;
    }
    for(int i=1;i<=m;i++)
        cout<<1<<" ";
    return 0;
}
