#include<bits/stdc++.h>
using namespace std;
int ea[200005][35],a[200005],ans,n,m,s;
bool del[200005];
map<int,int>ma;
void zh(int x)
{
	int k=0;
	while(x)
	{
		k++;
		int y=x%2;
		x/=2;
		ma[k]+=y;
		ea[s][k]=y;
	}
	return ;
}
void search(int x,int dl)
{
	if(x==1) return ;
	for(int i=x-1;i>0;i--)
	{
		if(ma[i]>=m)
		{
			ans+=pow(2,i-1);
			for(int j=1;j<=n;j++)
			{
				if(!ea[j][i])
				{
					for(int k=i;k>0;k--)
					{
						if(ea[j][k]) ma[k]--;
					}
				}
			}
			search(i,min(ma[i]-m,dl));
			break;
		}
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		s++;
		zh(a[i]);
	}
	for(int i=31;i>=1;i--)
	{
		if(ma[i]>=m)
		{
			search(i,ma[i]-m);
			break;
		}
	}
	cout << ans;
	return 0;
}

