#include <bits/stdc++.h>
using namespace std;
int a[3000000],ans[3000000]={0};
int n,m;
void w(int x) {
	for(int i=x;i<=n;i++) {
		for(int j=n;j>=i;j--) {
			if(a[i]==a[j]&&i!=j) {
				i=j-1;
				break;
			} else if(j == i) ans[a[i]]++;
		}
	}
} 
int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];	
	for(int i=1;i<=n;i++) w(i);	
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;	
}
