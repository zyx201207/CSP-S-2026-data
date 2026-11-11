#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m;
long long a[500005],b[500005];
bool ch(int x)
{
	bool f=0;
	for(int i=x;i<=n;i++)
		if((a[i]*x)-(b[i]-b[i-x])<=m) {f=1;break;}
	return f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	int L=1,R=n,mid;
	while(L<=R)
	{
		mid=(L+R)/2;
		if(ch(mid)) L=mid+1,ans=mid;
		else R=mid-1;
	}
	cout<<ans;
	return 0;
}
