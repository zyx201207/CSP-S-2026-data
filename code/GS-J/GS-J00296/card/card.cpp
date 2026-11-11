#include<bits/stdc++.h>
using namespace std;
int n,m,A[1010],B[1010],C[1010],i=1,p=1,o;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int j=1; j<=n; j++) {
		cin>>A[j];
	}
	for(int s=1; s<=n; s++) {
		for(int j=1; j<=n; j++) {
			C[j]=A[j];
		}
		for(int l=i; l<=n; l++) {
			for(int x=l+1; x<=n; x++) {
				o=C[l];
				if(C[l]==C[x]) {
					for(int f=l; f<=x; f++) {
						C[f]=0;
					}
					C[x]=o;
				}
			}
		}
		for(int j=i; j<=n; j++) {
			for(int v=1; v<=m; v++) {
				if(C[j]==v) {
					B[v]++;
				}
			}
		}
		i++;

	}
	for(int j=1; j<=m; j++) {
		cout<<B[j]<<" ";
	}
	return 0;
}
