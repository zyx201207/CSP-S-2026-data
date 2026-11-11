#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m,a[MAXN],b[MAXN],c[MAXN];
bool check(int x){
//	cout<<x<<":"<<endl;
	if(x>n) return 0;
	int mn=4e18,cnt=0;
	for(int i=2;i<=x;i++) cnt+=(c[x]-c[i-1]);
	mn=cnt;
//	cout<<"1-x:"<<cnt<<endl;
	for(int i=x+1;i<=n;i++) cnt-=(c[i]-c[i-x]),cnt+=(x*b[i]),mn=min(mn,cnt);//,cout<<i-x+1<<'-'<<i<<":"<<cnt<<endl;;
	return mn<=m; 
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) b[i]=a[i]-a[i-1],c[i]=c[i-1]+b[i];
///	cout<<"C=";
//	for(int i=1;i<=n;i++) cout<<c[i]<<' ';
//	cout<<endl;
	int l=1,r=n+1,mid,ans=1;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1; 
	} 
	cout<<ans;
	return 0;
}
