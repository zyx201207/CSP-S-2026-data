#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2e5+10;

ll a[N];
int n,m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m; 

	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	for(int k=n-m+1;k>=1;k--)
	{
		bool flag=false;
		for(int i=k;i<=n;i++)
		{
			ll xx=a[k],yy=0;
			while(xx>0)
			{
				xx=xx/2;
				yy++;
			}
			ll zz=a[i]>>yy;
			zz=zz<<yy;
			if(a[k]==(a[i]-zz))	
			{
				flag=true;
				break;
			}
		}
		if(flag==true){cout<<a[k];break;} 	
	}
	
	return 0;
}

