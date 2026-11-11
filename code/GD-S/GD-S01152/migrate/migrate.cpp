#include<bits/stdc++.h>
#define T_T return 0
using namespace std;
long long c,t;
long long n,d;
long long a[1000010];
int main(){
	freopen("migrate","r",stdin);
	freopen("migrate","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				long long last=a[i],sum=1,l[100010],r[100010];
				l[sum]=a[i];
				for(int k=i+1;k<=j;k++)
				{
					if(a[k]-last>d)
					{
						l[++sum]=a[k-1];
						r[sum]=k;
						last=a[k-1];
					}
				}
				int f=0;
				last=a[j];
				for(int k=j-1;k>=i;k--)
				{
					if(last-a[k]>d)
					{
						if(a[k+1]!=l[sum]) f++;
						sum--;
						last=a[k+1];
					}
				}
				if(f==1) ans++;
			}
		}
		cout<<ans<<endl;
	}
	T_T;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
