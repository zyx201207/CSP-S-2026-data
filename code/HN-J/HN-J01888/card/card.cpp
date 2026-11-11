#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[500001],h,ans[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		h=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=h;k++){
				if(b[k]==a[j]){
					h=k-1;
					break;
				}
			}
			h++;
			b[h]=a[j];
		}
		for(int j=1;j<=h;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
