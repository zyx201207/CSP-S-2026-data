#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],l[N],r[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i],l[i]=r[i-1]+1,r[i]=r[i-1]+a[i];
	long long m=r[n];
	int i=1,j=n;
	long long idi=0,idj=m+1;
	long long ans=0;
	while(i<j)
	{
		long long now=min(r[i],m-r[j-1]);
		if(c[i]!=c[j]) ans+=now-idi;
		idi=now,idj=m-now+1;
		if(r[i]<=now) i++;
		if(m-r[j-1]<=now) j--;
	}
	cout<<ans;
	return 0;
}
