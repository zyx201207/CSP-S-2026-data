#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;

int n,m;
int a[N];

bool cmp(int x,int y)
{
	return x>y;
}

void bl()
{
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	
	int ans=a[1];
	for(int i=2;i<=m;i++) ans&=a[i];
	
	cout<<ans;
	return ;
}

void m1()
{
	int maxn=-1e18;
	sort(a+1,a+1+n,cmp);
	cout<<a[1];
	return ;
}

void mn()
{
	int ans=a[1];
	for(int i=2;i<=n;i++)
	{
		ans&=a[i];
	}
	
	cout<<ans;
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	if(m==1)
	{
		m1();
		return 0;
	}
	else if(m==n)
	{
		mn();
		return 0;
	}
	else bl();
	return 0;
}
