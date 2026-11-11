#include <bits/stdc++.h>
using namespace std;
long long n,zfs=0,z,t=1,ans;
string x;
struct xc{
	long long a;
	char c;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		zfs+=a[i].a;
	}
	z=zfs/2;
	for(long long i=1;i<=n;i++){
		for(long long l=1;l<=a[i].a;l++){
			x[t]=a[i].c;
			t++;
		}
	}
	for(long long i=1;i<=z;i++){
		if(x[i]!=x[zfs-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;	
}
