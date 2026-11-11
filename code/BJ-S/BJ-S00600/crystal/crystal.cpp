#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[200005],d[200005],s1[200005],s2[200005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        d[i+1]=a[i]-a[i+1];
    }
    d[n+1]=0;
    for(int i=1;i<=n;i++){
        s1[i]=s1[i-1]+d[i];
    }
    for(int i=1;i<=n;i++){
        s2[i]=s2[i-1]+s1[i];
    }
    ll cnt=0;
    for(int i=n;i>=1;i--){
        ll l=1,r=i,mid=0;
        ll f=s1[n-i+1];
        cout<<f<<" ";
        while(l<=r){
            mid=(l+r)/2;
            ll g=i-mid;
            if(s2[mid]-f*g==m){
                cnt=max(cnt,mid);
                break;
            }else if(s2[mid]-f*g<m){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        cnt=max(cnt,l);
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
