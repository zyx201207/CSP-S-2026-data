#include<bits/stdc++.h>
using namespace std;

long long a[200005];
string now,pre,s;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n,x,cnt=0,minn,ans=0;
    cin>>n;
    while(n--){
        cin>>x>>now;
        if(now==pre)
            a[cnt-1]+=x;
        else{
            a[cnt++]=x;
            s+=now;
        }
        pre=now;
    }
    int l=0,r=cnt-1;
    while(l<r){
        if(a[l]==0) l++;
        if(a[r]==0) r--;
        minn=min(a[l],a[r]);
        a[l]-=minn;
        a[r]-=minn;
        if(s[l]!=s[r]){
            ans+=minn;
        }
    }
    cout<<ans;
    return 0;
}