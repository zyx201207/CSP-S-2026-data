#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005];
int tong[10005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	int j=1;
	tong[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1])
		{
			tong[j]+=1;
		}
		else
		{
			j++;
			tong[j]=1;
		}
	}
	
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			for(int z=i+1;z<=n;z++)
			{
				a[i]=a[i+1];
			}
		}
	}
	
	int Maxn=tong[1];
	for(int i=2;i<=j;i++)
	{
		if(tong[Maxn]>tong[i-1]) Maxn=i;
	}
	cout<<Maxn;
	int sum=tong[Maxn];
	for(int i=1;i<=j;i++){
		if(i==Maxn) continue;
		if((a[Maxn]-a[i])<=m){
			if((int)(m/(a[Maxn]-a[i]<=tong[i]))){
				sum+=(int)(m/(a[Maxn]-a[i]));
				break;
			}
			else{
				sum+=tong[i];
				m-=(int)((a[Maxn]-a[i]<=a[i])*tong[i]);
			}
		}
	}
	return 0;
}
