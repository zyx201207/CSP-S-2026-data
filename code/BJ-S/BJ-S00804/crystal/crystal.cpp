#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m;
int a[N];
int S[N];
int Calc(int l,int r){
    return (r-l+1)*a[r]-(S[r]-S[l-1]);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)S[i]=S[i-1]+a[i];
    int Ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=l+r>>1;
            if(Calc(mid,i)<=m)r=mid;
            else l=mid+1;
        }
        Ans=max(Ans,i-l+1);
    }
    cout<<Ans<<endl;
    return 0;
}