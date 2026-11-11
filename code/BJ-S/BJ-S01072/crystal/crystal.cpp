#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
long long check1(long long an,int id){
    long long ans=0,anss=0,i=id-1,x=1;
    while(anss<m&&i>=1){
        ans+=(an-a[i]);
        x++;
        i--;
        anss=ans+(an-a[i]);
    }
    return x;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=2;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(check1(a[i],i)>ans){
            ans=check1(a[i],i);
        }/**/
    }

    cout<<ans;
    return 0;
}

