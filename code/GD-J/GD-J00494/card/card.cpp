#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n,m,a[N],b[N],ans[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++) {
			b[j] = a[j];
			for(int z=i;z<j;z++){
				if(b[z] == a[j]) {
					for(int q=z;q<j;q++) b[q] = 0;
				}
			} 
		}
		for(int p=i;p<=n;p++) {
			if(b[p]!=0) ans[b[p]]++;
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=a[n];i++) cout<<ans[i]<<' ';
	return 0;
} 
