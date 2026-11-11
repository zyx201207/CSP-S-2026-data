#include<bits/stdc++.h>
using namespace std;
const int A=5e5+5;
int n,m,b[A],lll[A];
signed main() {
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>b[i];
	}
//	for(int i=1; i<=n; i++) {
//		bool a[m];
//		for(int j=i; j<=n; j++) {
//			if(a[b[j]]==1) {
//				for(int x=i; x<=j; x++) {
//					a[x-i+1]=0;
//				}
//			}
//			a[b[j]]=1;
//		}
//		for(int j=i; j<=n; j++) {
//			if(a[j]==1) {
//				lll[j-i+1]+=1;
//			}
//		}
//	}
	bool a[m+1];
	for(int i=1; i<=n; i++) {
		for(int j=1;j<=m;j++)
		{
			a[j]=0;
		}
		for(int j=n; j>=i; j--) {
			if(a[b[j]]==1)
			{
				break;
			}
			lll[b[j]]+=1;
			a[b[j]]=1;
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<lll[i]<<" ";
	}
	return 0;
}
