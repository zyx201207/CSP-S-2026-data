#include<bits/stdc++.h>
using namespace std;
long long num=0,ans=0;
long long c,n,m,d,q,w[10100],k[5100],a[10100][10100],t[10100][10100],x[100010],y[100010],vis[1010][1010];
void dfs(long long he,long long zo,long long tn,long long an) {
	if(a[he][zo]==tn) {
		ans=an+w[tn-1]+t[he][zo];
		return;
	} else {
		for(int i=zo+1; i<k[he]; i++) {
			if(vis[he][i]==0) {
				dfs(he,i,tn,an);
				vis[he][i]=1;
			}
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<k[i]; j++) {
				if(he!=i) {
					if(a[he][zo]==a[i][j]&&vis[i][j]==0) {
						vis[i][j]=1;
						dfs(i,j,tn,an+t[he][zo]+t[i][j]);
					}
				}
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0; i<m; i++) {
		cin>>w[i];
	}
	for(int i=0; i<n; i++) {
		cin>>k[i];
		for(int j=0; j<k[i]; j++) {
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0; i<q; i++) {
		cin>>x[i]>>y[i];
	}
	for(int k1=0; k1<q; k1++) {
		ans=0x3f3f3f3f;
		num=0x3f3f3f3f;
		for(int i=0; i<n; i++) {

			for(int j=0; j<k[i]; j++) {

				if(a[i][j]==x[k1]) {
					dfs(i,j,y[k1],0+t[i][j]+w[x[k1]-1]);
				}
				if(ans<num) {
					num=ans;

				}
				for(int ac=0; ac<n; ac++) {
					for(int ak=0; ak<n; ak++) {
						vis[ac][ak]=0;
					}
				}
			}

		}
		cout<<num<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
