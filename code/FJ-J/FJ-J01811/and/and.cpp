#include<bits/stdc++.h>
using namespace std;
const int N =200010;
long long n,a[N],m,cnt=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==a[i-1])
		{
			cnt++;
		}
	}
	if(cnt==n)
	{
		cout<<a[1];
		return 0;
	}
	sort(a+1,a+n+1);
	int f=a[n];
	for(int i=n-1;i>=n-m+1;i--)
	{
		f=f&a[i];
	}
	cout<<f;
	return 0;
}
