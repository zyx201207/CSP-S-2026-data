#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int a[N];
int z[N];
int wz[M];
long long num[M];
int n,m,top;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
//		cout<<"i:"<<i<<'\n';
		top=0;
		memset(wz,0,sizeof(wz));
		for(int j=i;j<=n;j++)
		{
//			cout<<"j:"<<j<<'\n';
			if(!wz[a[j]])
			{
				top++;
				z[top]=a[j];
				wz[a[j]]=j;
//				cout<<"out";
			}
			else
			{
				while(a[j]!=z[top])
				{
					wz[z[top]]=0;
					top--;
				}
//				cout<<"in";
			}
//			for(int k=1;k<=top;k++)
//			{
//				cout<<z[k];
//			}
//			cout<<'\n';
		}
		for(int j=1;j<=m;j++)
		{
			if(wz[j]) num[j]++;
		}
//		for(int j=1;j<=m;j++) cout<<num[j]<<" ";
//		cout<<'\n';
	}
	for(int i=1;i<=m;i++)
	{
		cout<<num[i]<<" ";
	}
	return 0;
}
