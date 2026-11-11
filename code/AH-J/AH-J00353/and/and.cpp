#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
bool a[MAXN][50],f[50];
long long maxn;
void getn(long long x,int i)
{
	long long c=0;
	while(x)
	{
		a[i][++c]=x&1;
		x=x>>1;
	}
	maxn=max(maxn,c);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		long long x;cin>>x;
		getn(x,i);
		q.push(i);
	}
	for(int i=maxn;i>0;i--)
	{
		int k=q.size(),cnt=0;
		for(int l=1;l<=k;l++){
			int j=q.front();
			q.pop();
			q.push(j);
			if(a[j][i])  cnt++;
		}
		if(cnt>=m)
		{
			while(k--){
			int j=q.front();
			q.pop();
			if(a[j][i])  q.push(j);
			}
		}
		else f[i]=1;
	}
	long long ans=0;
	for(long long i=1,j=1;i<=maxn;i++,j*=2)
	{
		if(!f[i])  ans+=j;
	}
	cout<<ans;
	return 0;
}

