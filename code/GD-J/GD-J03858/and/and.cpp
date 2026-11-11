#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
long long ans[N][35];
bool vis[N];
long long anss;
void make(int pos,int x)
{
	int k=32;
	for(int i=x; i>=1; i/=2)
	{
		ans[pos][k]=i%2;
		k--;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);	
	}
	for(int i=1; i<=n; i++)
	{
		make(i,a[i]);
	}
	for(int i=1; i<=n; i++) vis[i]=true;
	for(int j=0; j<=32; j++)
	{
		int cnt=0;
		for(int i=1; i<=n; i++)
		{
			if(!vis[i]) continue;
			if(ans[i][j]) cnt++;
		}
		if(cnt>=m)
		{
			for(int i=1; i<=n; i++)
			{
				if(!vis[i]) continue;
				if(!ans[i][j]) vis[i]=false;
			}
			anss+=pow(2,32-j);
		}
	}
	cout<<anss;
	return 0;
} 
