#include<bits/stdc++.h>
using namespace std;
int n,m,ans[500005],a[500005],q[500005],l,r;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=n;i>=1;i--){
		l=1;r=0;
		for(int j=i;j<=n;j++){
			for(int k=l;k<=r;k++){
				if(q[k]==a[j]){
					r=k-1;
					break;
				}
			}
			r++;
			q[r]=a[j];
		}
		for(int j=l;j<=r;j++)ans[q[j]]++;
	}
	for(int i=1;i<=m;i++)cout << ans[i] << ' ';
	return 0;
}
