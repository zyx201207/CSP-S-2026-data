#include<bits/stdc++.h>
using namespace std;

const int N=1e6;

long long a[N],m,n,ans=-1;
bool used[N][32];
bool cosd[N];
int awa[32];
int main()//ɸ 
{
cin.tie(0);
ios::sync_with_stdio(0);
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);

cin>>n>>m;
for(long long i=0;i<n;i++)
{
	cin>>a[i];
	int tj=1;
	for(int j=1;j<31;j++)
	{
		if(a[i]&tj)
		{
		used[i][j]=1;
		awa[j]++;
		}
		tj=tj<<1;
	}
}
//for(long long i=0;i<n;i++)
//{
//	for(int j=1;j<=8;j++)
//	{
//		cout<<int(used[i][j]);
//	}cout<<"\n";
//}

//
//	for(int j=0;j<32;j++)
//	{
//
//		cout<<awa[j]<<" ";
//	}
//cout<<"\n";

int chr=0;
int fir=-1;
	for(int i=31;i>0;i--)
	{
//			for(int j=0;j<32;j++)
//	{
//
//		cout<<awa[j]<<" ";
//	}
//cout<<"\n";

		bool fg=0;
		if(awa[i]>=m)
		{
			fir=max(i,fir);
			for(long long j=0;j<n;j++)
			{
			if(used[j][i] )
				{
					if(i==fir)
					{
						cosd[j]=1;
					chr++;		
//					cout<<a[j]<<" chosed on "<<i<<"\n";		
					}
				}
			else
				{
					if(cosd[j]==1)
						{
						cosd[j]=0;
						chr--;
//						cout<<a[j]<<" unchosed on "<<i<<"\n";
						}
					if(chr==m && i!=fir)
					{
					fg=1;
//					cout<<"EXIT\n";
					break;	
					}	
					for(int tpj=0;tpj<31;tpj++)
					{
						if(used[j][tpj]==1)
						{
							awa[tpj]--;
							used[j][tpj]=0;
						}
					}
				}	
			}
		}
		else
		{
//			cout<<"ohNO! "<<i<<"\n";
			for(long long j=0;j<n;j++)
			{
				used[j][i]=0;
			}
		}
		if(fg)
		{
			break;
		}
	}
//	int tep=1<<30;

//for(long long i=0;i<n;i++)
//{
//	for(int j=1;j<=8;j++)
//	{
//		cout<<int(used[i][j]);
//	}cout<<"\n";
//}


		for(long long j=0;j<n;j++)
		{
			if(cosd[j])
			{
				if(ans==-1)
				ans=a[j];
				ans=ans&a[j];
//				cout<<a[j]<<" ";
			}
		}
//		tep=tep>>1; 
//	cout<<"\n";

cout<<ans;
return 0;	
}

