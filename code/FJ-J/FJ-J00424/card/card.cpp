#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],ans[500005],r;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int h=1;h<=n;h++){
		r=h-1;
		for(int i=h;i<=n;i++){
			b[++r]=a[i];
			for(int j=r-1;j>=h;j--){
				if(b[j]==b[r]){
					r=j;
					break;
				}
			}
		}
		for(int i=h;i<=r;i++){
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
