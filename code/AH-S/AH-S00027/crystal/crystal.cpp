#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int n;
ll m;
int ans;
ll a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    bool fl1=1,fl2=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i){
            fl1=0;
        }
        if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
            fl2=0;
        }
    }
    if(n>10000&&fl1==1){
        ll s=sqrt(m*2);
        ll x=s*(s-1)/2,y=s*(s+1)/2;
        if(m>=x&&m<y){
            cout<<s;
        }else if(m>=y){
            cout<<s+1;
        }
    }else if(n>10000&&fl2==1){
        m=m/(a[2]-a[1]);
        ll s=sqrt(m*2);
        ll x=s*(s-1)/2,y=s*(s+1)/2;
        if(m>=x&&m<y){
            cout<<s;
        }else if(m>=y){
            cout<<s+1;
        }
    }else{
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
            ll sum=0;
            int cnt=0;
            for(int j=i;j>=1;j--){
                sum+=a[i]-a[j];
                if(sum>m){
                    break;
                }
                cnt++;
            }
            ans=max(ans,cnt);
        }
        cout<<ans;
    }
    return 0;
}
