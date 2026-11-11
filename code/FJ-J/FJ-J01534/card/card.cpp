#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],t;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=n;j>=1;j--) {
			if(a[j]==a[i]) {
				t=j;
				b[a[j]]++;
				break;
			}
			else b[a[j]]++;
		}
		for(int j=n,k=1;j>=t+1;j--) {
			if(a[j]==a[t+k]&&j!=t+k) {
				for(int p=t+k;p<=j-1;p++)
					b[a[p]]--;	
			}
			k++;
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}