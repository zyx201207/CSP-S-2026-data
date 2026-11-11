#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,m,ma=-1;
ll a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1];
    int l=1;
    for(int r=1;r<=n;r++){
        if(a[r]*(r-l+1)-(s[r]-s[l-1])<=m)ma=max(ma,r-l+1);
        else l++;
    }
    cout<<ma;
    return 0;
}
