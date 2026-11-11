#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int N=5e5+500;
LL n,m,a[N],ans,s[N],k=1;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int x=1;x<=n;x++){
        cin>>a[x];
    }
    sort(a+1,a+n+1);
    for(int x=1;x<=n;x++){
        s[x]=s[x-1]+a[x];
    }
    LL nd,ans=0;
    for(int x=1;x<=n;x++){
        while((x-k+1)*a[x]-(s[x]-s[k-1])>m && k<=x){
            k++;
        }
        if((x-k+1)*a[x]-(s[x]-s[k-1])<=m){
           ans=max(ans,(LL)(x-k+1)); 
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/