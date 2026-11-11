#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[300005],l,ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		l=0;
		for(int j=1;j<=m;j++){
			c[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(c[a[j]]==1){
				while(b[l]!=a[j]){
					c[b[l]]--;
					l--;
				}
				c[b[l]]--;
				l--;
			}
			c[a[j]]++;
			l++;
			b[l]=a[j];
		}
		for(int j=1;j<=m;j++){
			if(c[j]==1){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
