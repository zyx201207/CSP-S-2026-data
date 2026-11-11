#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500050],c[500050],q[500050];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
		q[i]=q[i-1]+i*c[i];
	}
	for(int i=1;i<n;i++){
		if(q[i]>m){
			cout<<i;
			return 0; 
		}
	}
	cout<<1; 
	return 0;
}
