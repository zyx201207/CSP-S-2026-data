#include<iostream>
#include<vector>
using namespace std;
int c,n,m,d,q,w[500005],a[505][25],t[505][25],k,s,e,ans=99999999;//
bool b[505][25];
void find(int st,int en,int co)
{
	if(b[st][en])return;
	//cout<<st<<' '<<en<<' '<<co<<endl;
	if(st==en)
	{
		ans=min(ans,co);
		return;
	}
	for(int i=0;i<=n-1;i++)
	{
		for(int j=1;j<=a[i][0];j++)
		{
			if(a[i][j]==st)
			{
				for(int l=j+1;l<=a[i][0];l++)
				{
					b[i][l]=1;
					find(a[i][l],en,co+t[i][l]+t[i][j]);
				}
				break;
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<=m-1;i++)cin>>w[i];
	for(int i=0;i<=n-1;i++)
	{
		cin>>k;
		a[i][0]=k;

		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
			
		}
	}
	for(int i=0;i<=q-1;i++)
	{
		cin>>s>>e;
		ans=9999999;
		for(int l=0;l<=500;l++)
		{
			for(int j=0;j<=20;j++)b[l][j]=0;
		}
		find(s,e,0);
		cout<<ans+w[s-1]+w[e-1]<<endl;
	}
	return 0;
}
