#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int tmp[N];//大到小排序的第i个数的二进制有几位 
int a[N][35];//a[i][j]:第i个数的二进制第j位 
long long ls_a[N];
bool f[35];//f[i][j]:从大到小排序的前m个数的第j位是否有0 
int n;
void cf(int x1,int ls_i)
{
	while(x1)
	{
		tmp[ls_i]++;
		a[ls_i][tmp[ls_i]]=x1%2;
		if(!(x1%2)) f[tmp[ls_i]]=0;
		x1=x1/2;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>ls_a[i];
	sort(ls_a+1,ls_a+1+n);
	memset(f,1,sizeof(f));
	cout<<ls_a[n]<<" "<<ls_a[n-1]<<'\n';
	for(int i=n;i>=n-m+1;i--) cf(ls_a[i],i);
	long long num=0;
	long long ls=1;
	for(int i=1;i<=34;i++) cout<<f[i];
	for(int i=1;i<=tmp[m];i++)
	{
		num+=ls*f[i];
		ls=ls*2;
	}
	cout<<num;
	return 0;
}
