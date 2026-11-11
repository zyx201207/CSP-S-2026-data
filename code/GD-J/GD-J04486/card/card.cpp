# include <bits/stdc++.h>
using namespace std;
const int N=5e5+10 ;

int n , m , a[N] ;
int ans[N] , ta[N] , vis[N];
int len ;

int main()
{
	freopen("card.in","r",stdin) ;
	freopen("card.out","w",stdout) ;
	
	cin >> n >> m ;
	for(int i=1; i<=n ; i++)
	{
		cin >> a[i] ;
	}
	
	for(int i=1; i<=n ; i++)
	{
		memset(ta,0,sizeof(ta)) ;
		memset(vis,0,sizeof(vis)) ;
		len=0 ;
		for(int j=i ; j<=n ; j++)
		{
			if(!vis[a[j]])
			{
				
				ta[++len]=a[j] ;
				vis[a[j]]=len ;
			}
			else
			{
				int cnt=len ;
				for(int k=vis[a[j]]+1 ; k<=cnt ; k++)
				{
					vis[ta[k]]=0 ;
					ta[k]=0 ;
					len-- ;
				}
			}
		}
		
		for(int j=1 ; j<=len ; j++)
		{
			ans[ta[j]]++ ;
		}
	}
	
	for(int i=1 ; i<=m ; i++)
	{
		cout << ans[i] << " " ;
	}
	return 0;
}

