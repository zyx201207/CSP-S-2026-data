#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll a[500005];
ll c[500005];
ll q[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);//i am so so so so happy!!!!!
    for(int i=2;i<=n;i++){
        c[i]=c[i-1]+a[i]-a[i-1];
        q[i]=q[i-1]+c[i];
    }
    c[1]=a[1];q[1]=a[1];
    if(m==0){
        int ans=0,cnt=1;
        for(int i=2;i<=n;i++){
            if(a[i]==a[i-1])cnt++;
            else ans=max(ans,cnt),cnt=1;
        }
        cout<<ans<<endl;
        return 0;
    }
    int t=0;
    while(c[n]*t-q[n-1]+q[n-t-1]<=m&&t<n)t++;
    for(int i=n-1;i>=t+1;i--){
        if((c[i]*(t-1)-q[i-1]+q[i-t])>m)continue;
        while(((c[i]*t-q[i-1]+q[i-t-1])<=m)&&t<i)t++;
    }
    cout<<t<<endl;
    return 0;
}

