#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long n,m,a[N];

bool cmp(int a,int b)
{
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int maxn=-1,maxm;
	a[0]=0;
	bool op=true;
	int b=a[2]-a[1];
	for(int i=1;i<=n;i++)
	{
		if(a[i-1]-a[i]!=b)
		{
			op=0;
			break;
		}
	}
	if(op)
	{
		long long ss=0;
		int time=1;
		while(ss<=m)
		{
			ss+=a[time];
			time++;
		}
		cout<<time;
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long dp[N];
		for(int j=1;j<=n;j++){
			dp[j]=dp[j-1]+a[j];
			if((dp[j]+m)/j==a[j]){
			maxn=max(maxn,j);
			}	
		}	
	}
	maxn=max(maxn,maxm);
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
