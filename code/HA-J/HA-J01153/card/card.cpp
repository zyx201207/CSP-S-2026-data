#include <bits/stdc++.h>
using namespace std;
int ans[300010] , a[500010];
bool c[300010];
int b[300010] , l;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n , m;
	scanf("%d%d",&n,&m);
	for ( int i = 1 ; i <= n ; i ++ )
		scanf("%d",&a[i]);
	for ( int i = 1 ; i <= n ; i ++ )
	{
		l = 0;
		memset(c,0,sizeof c);
		for ( int j = i ; j <= n ; j ++ )
		{
			if ( c[a[j]] )
			{
				while ( b[l] != a[j] )
					c[b[l--]] = 0;
				l --;
			}
			b[++l] = a[j];
			c[a[j]] = 1;
		}
		for ( int j = 1 ; j <= l ; j ++ )
			ans[b[j]] ++;
	}
	for ( int i = 1 ; i <= m ; i ++ )
		printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
