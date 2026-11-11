#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+5,M=25;
int n,m,a[N],b[N],lg[N],f[N][M]; 
bool check(int x,int y){
	if(y>n)return 0; 
	int sum=lg[y-x+1],mx=max(f[x][sum],f[y-(1<<sum)+1][sum]);
	if(mx*(y-x+1)<=m+b[y]-b[x-1])return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=2;i<N;i++)lg[i]=lg[i/2]+1;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)f[i][0]=a[i],b[i]=b[i-1]+a[i];
	for(int j=1;j<=lg[n];j++)
	{
		for(int i=1;i<=n-(1<<j)+1;i++)
		{
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(i,mid)==1)l=mid+1;
			else r=mid-1;
		}
		if(check(i,l)==0)l--;
		ret=max(ret,l-i+1);
	}
	cout<<ret;
	return 0;
}
