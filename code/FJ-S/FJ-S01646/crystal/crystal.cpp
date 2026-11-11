#include<bits/stdc++.h> 
using namespace std;
const int N=5e5+10;
long long a[N],maxx=-0x3f,cnt=1;//f[i][j]表在目标变为i，M=J时能取到的最大值/ 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;cin>>n;
	long long m;cin>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	for(long long j=0;j<=m;j++) {//目标为i剩余j次操作 
		long long sp=m-j;
		cnt=1;
		for(int k=i-1;k>=1;k--)
		{
		if(sp-a[i]+a[k]>=0)
		{
		sp=sp-a[i]+a[k];
		if(cnt+1<=n)
			cnt++;
	}
	maxx=max(maxx,cnt);
	}
}
cout<<maxx;
	return 0;
}
