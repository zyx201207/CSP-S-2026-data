#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[21000],a[21000][600],t[21000][600];
long long tu[21000][21000];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	long long len=2*m+n+1;
	for(long long i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(long long j=1; j<=len; j++)
		for(long long i=1; i<=len; i++) {
			if(i==j)tu[i][j]=0;
			else tu[i][j]=0;
		}
	for(long long i=1; i<=n; i++) {
		long long k;
		cin>>k;
		for(long long j=1; j<=k; j++) {
			cin>>a[i][j]>>t[i][j];
			tu[m+i][a[i][j]]=0;
			tu[m+n+j][a[i][j]]=t[i][j];
		}
	}
	for(long long k=1; k<=len; k++) {
		for(long long i=1; i<=len; i++) {
			for(long long j=1; j<=len; j++) {
				if(tu[i][j]>tu[i][k]+tu[k][j]) {
					tu[i][j]=tu[i][k]+tu[k][j];
				}
			}
		}
	}
	for(long long i=1; i<=q; i++) {
		long long l,r;
		cin>>l>>r;
		cout<<tu[l][r]+w[l]+w[r];
	}
	return 0;
}//rp++!!
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
 */
