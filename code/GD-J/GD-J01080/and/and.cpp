#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
struct ppp
{
	char k;
	int le;
}c[200005][100],b[200005][100];
int main()
{
		freopen("and.in","r",stdin);
		freopen("and.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		sort(a+1,a+1+n,greater<int>());
		for(int i=1;i<=n;i++)
		{
				long long y=a[i];
				int j=1;
				while(y)
				{
					c[i][j].k=char(y%2+int('0'));
					y/=2;
					j++;
				//	cout<<j<<"   "<<y%2<<"    "<<y<<"     "<<c[i][j]<<endl; 
				}
				c[i][0].le=j;
		}
		for(int i=1;i<=n;i++)
		{
			b[i][0].le=max(c[i][0].le,c[i+1][0].le); 
			for(int p=1;p<=b[i][0].le;p++)
			{
				if(c[i][p].k==c[i+1][p].k&&c[i+1][p].k=='1')
				b[i][p].k='1';
				else
				b[i][p].k='0';
			}
			b[i][0].le=max(c[i][0].le,c[i+1][0].le); 
		}
			b[1][0].le=max(b[1][0].le,b[2][0].le); 
			for(int p=1;p<=b[1][0].le;p++)
			{
				if(b[1][p].k==b[2][p].k&&b[1][p].k=='1')
				b[1][p].k='1';
				else
				b[1][p].k='0';
			}
		
		for(int p=b[1][0].le;p>=1;p--)
			{
				ans=ans+(b[1][p].k-'0')*pow(2,p-1);
			}
			cout<<ans;
			
		fclose(stdin);
		fclose(stdout);
	return 0;
} 
/*4 2
3 15 12 12*/
