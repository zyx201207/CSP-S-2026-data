#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],flag[300005],vis[500005],t[300005],l,r;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for( int i = 1;i<=n;i++ ) cin >> a[i];
	for( int k = 1;k<=n;k++ ){
		memset(flag,0,sizeof(flag));
		memset(vis,0,sizeof(vis));
		l = 0;
		r = 0;
		for( int i = k;i<=n;i++ ){
			int x = a[i];
			if( flag[x] == 0 ) flag[x] = i;
			else{
				int ll = flag[x],rr = i-1;
				if( ll >= l && ll <= r || vis[ll] == 1 ) flag[x] = i;
				else if( ll < l ){
					l = ll;
					r = rr;
				}
				else{
					for( int j = l;j<=r;j++ ){
						vis[j] = 1;
					}
					l = ll;
					r = rr;
				}
				flag[x] = i;
			}
		}
		for( int i = k;i<=n;i++ ){
			if( i == l ){
				i = r;
				continue;
			}
			if( vis[i] == 1 ) continue;
			t[a[i]] ++;
		}
	}
	for( int i = 1;i<=m;i++ ){
		cout << t[i] << " ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
