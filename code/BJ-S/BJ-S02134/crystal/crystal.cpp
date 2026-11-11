#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[100010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long t=m;
    for(int i=1;i<=n;i++) cin>>a[i];
    int cnt=0;
    for(int j=1;j<=n;j++){
        int ans=0;
        m=t;
        for(int i=j;i>0;i--){
            if(m>=a[j]-a[i]){
                m-=a[j]-a[i];
                ans++;
            }else{
                continue;
            }
        }
        if(ans>cnt) cnt=ans;
    }
    cout<<cnt;
    return 0;
}

