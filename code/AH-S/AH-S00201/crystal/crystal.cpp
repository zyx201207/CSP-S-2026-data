#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long a[MAXN],n,m;
bool check(int x)
{
	long long minn=INT_MAX,s=0;
	for(int i=1;i<=x;i++)  s+=a[i];
	for(int i=x;i<=n;i++)
	{
		minn=min(minn,(x)*a[i]-s);
		s-=a[i-x+1],s+=a[i+1];
//		cout<<minn<<" ";
	}
	return minn<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+n+1);
	long long l=1,r=n;
	while(l<=r)
	{
		long long mid=(l+r)/2;
//		cout<<l<<" "<<r<<" "<<mid<<"\n  ";
		if(check(mid))  l=mid+1;
		else  r=mid-1;
//		cout<<"\n";
	}
//	if(check(l+2))  cout<<l+2;
//	else  if(check(l+1))  cout<<l+1;
//	else  if(check(l))  cout<<l;
//	else  if(check(l-1))  cout<<l-1;
//	else  cout<<l-2;
cout<<r;
	return 0;
}

