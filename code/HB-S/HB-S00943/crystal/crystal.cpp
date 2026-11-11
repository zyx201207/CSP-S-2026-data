#include <bits/stdc++.h>
using namespace std;
const int mx=5E5+10;
long long a[mx],n,m,l,r,ans,b[mx];
bool can(int len){
    long long sum=0,s=0;
    for(int i=1;i<len;i++) sum+=b[i]*i,s+=b[i];
    int x=n-len+1;
    bool bl=0;
    for(int j=2;j<=x;j++){
        if(sum<=m) return 1;
        sum-=s;
        sum+=(len-1)*b[j-2+len];
        s-=b[j-1];
        s+=b[j-2+len];
    }
    if(sum<=m) return 1;
    return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
        b[i]=a[i+1]-a[i];
	l=1,r=n;
	while(l<=r){
        long long mid=(l+r)/2;
        if(can(mid)) ans=mid,l=mid+1;
        else r=mid-1;
	}
	cout<<ans;
	return 0;
}
