#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.out","w",stdout);
    freopen("crystal.in","r",stdin);
    long long n,m,s[500005]={},a[500005]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int fin=n;
    long long sum=0,ans=0,l=0;
    for(int i=n;i>0;i--){
        sum-=(a[i+1]-a[i])*l;
        fin=min(fin,i);
        while(sum<=m&&fin>0){
            sum+=(a[i]-(a[--fin]));
        }
        l=i-fin;
        ans=max(ans,l);
    }
    cout<<ans;
}

