#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,ans=0,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{long long x;
		cin>>x;
		ans=max(ans,x);
	 } 
	 cout<<ans;

	return 0;
}

