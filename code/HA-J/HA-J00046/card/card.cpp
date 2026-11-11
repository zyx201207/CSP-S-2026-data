#include<bits/stdc++.h>
using namespace std;
int n,m,x=100,s;
int ans[300010];
int a[500010];
int b[300010];
int c[300010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) { 
		for(int j=1; j<=m; j++) {
			b[j]=0;
			c[j]=0;
		}
		x=0;
		for(int j=i; j<=n; j++) {
			s=a[j];
			if(c[s]==0) {
				x++;
				b[x]=s;
				c[s]=x;
			} else {
				for(int k=c[s]+1; k<=x; k++) {
					c[b[k]]=0;
					b[k]=0;
				}
				x=c[s];
			}
		}
		for(int k=1; k<=x; k++) {
			ans[b[k]]++;
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
