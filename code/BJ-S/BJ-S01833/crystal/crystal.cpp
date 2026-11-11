#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define int long long
int a[500001];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=m;
    int r=1;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i!=1){
            l+=a[r]-a[i-1];
        }
        while(true){
            if((a[r+1]-a[r])*(r-i+1)<=l){
                l-=(a[r+1]-a[r])*(r-i+1);
                r++;
                if(r==n)break;
            }
            else{
                break;
            }
        }
        ans=max(ans,r-i+1);
        if(r==n){
            break;
        }
    }
    cout<<ans;
}

