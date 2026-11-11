#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],s,l,r,cnt,c;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
    }
    for(int i=1;i<n;i++){
        if(s<=m&&s+b[i]*i>m){
            r=i-1;
            break;
        }
        s+=b[i]*i;
        l+=b[i];
    }
    cnt=r+1;
    c=r;
    for(int i=1;i<n;i++){
        s-=l;
        l-=b[i];
        while(1){
            if(s<=m&&s+b[r+1]*(r-i+1)>m){
                break;
            }
            r++;
            s+=b[r]*(r-i);
            l+=b[r];
            if(r==n){
                r--;
                break;
            }
        }
        cnt=max(cnt,r-i+1);
    }
    cout<<cnt;
    return 0;
}
