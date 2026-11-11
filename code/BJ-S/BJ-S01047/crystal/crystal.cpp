#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500010];
//ll b[500010]; //jiaoxiayigedecha
ll need[500010];
ll n,m;
//ll n2n[500010];
int erfen(int left,int right) {
    if(left>right)return 0;
    int mid=(right-left)/2;
    if(need[right]<=m)return right;
    if(right==left)  {
        if(need[left]<=m)return left;
        return 0;
    }
    if(right==left+1) {
        if(need[right]<=m)return right;
        if(need[left]<=m)return left;
        return 0;
    }
    if(right=left+2) {
        if(need[right]<=m)return right;
        if(need[mid]<=m)return mid;
        if(need[left]<=m)return left;
        return 0;
    }
    if(need[mid]==m)return mid;
    if(need[mid]>m) {
        return erfen(left,mid);
    }
    if(need[mid]<m) {
        return erfen(mid,right);
    }
}
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    bool ta=1,tb=1;

    cin>>n>>m;
    //for(int i=1;i<=n;i++) {
     //   n2n[i]=(i*i)-i;
    //}
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(ta) {
            if(a[i]!=i) ta=0;
        }
        if(tb) {
            if(i>2) {
                if((a[i]-a[i-1])!=(a[i-1]-a[i-2]))
                    tb=0;
            }
        }
    }
    sort(a+1,a+n+1);
    //for(int i=0;i<=n;i++) cout<<a[i];
    if(ta) {
        ll ans=1;
        for(;(ll)(((ans*ans)-ans)/2)<=m;ans++);
        cout<<ans-1;
        return 0;
    }
    if(tb) {
        ll st=a[n]-a[n-1];
        ll cha=st-a[1]; //a[1]pianli

        for(int i=1;i<=n;i++) {
            a[i]+=cha;
        }

        //for(int i=0;i<=n;i++) cout<<a[i];
        ll ans2=1;
        //cout<<cha;
        //return 0;
        for(;(ll)((st*((ans2*ans2)-ans2))/2)<=m;ans2++);
        cout<<ans2-1;
        return 0;
    }

    int pl=a[1];//pianli
    for(int i=1;i<=n;i++) {
            a[i]-=pl;
    }
   // for(int i=1;i<n;i++) {
     //   b[i]=a[i+1]-a[i];
    //}
    int ans3=1;
    for(int i=n;i>=2;i--) {
        if(i<=ans3) {
            cout<<ans3;
            return 0;
        }
        for(int j=0;j<=n+3;j++)need[j]=0;
        for(int j=2;j<=i;j++) {
            need[j]=need[j-1]+a[i]-a[i-j+1];
        }
        if(need[ans3]<=m){
            int now=erfen(ans3,i);
            if(now>ans3) ans3=now;
            //cout<<need[i];
        }

    }
    cout<<ans3;
    return 0;
}
