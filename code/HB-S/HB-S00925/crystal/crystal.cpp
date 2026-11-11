#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
unsigned long long n,m,ans,cnt,num,a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    For(i,1,n)cin>>a[i];
    sort(a+1,a+1+n);
    For(i,1,n){
        ans=0,cnt=0;
        for(int j=i;j>=1;j--){
            if(a[i]-a[j]>=0){
                ans+=(a[i]-a[j]),cnt++;
                if(ans>m)ans-=(a[i]-a[j]),cnt--,j=0;
            }
        }
        num=max(num,cnt);
    }
    cout<<num;
    return 0;
}
