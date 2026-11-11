#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[a[j]]++;
			if(b[a[j]]==2){
				for(int k=j-1;;k--){
					if(a[k]==a[j]){
						b[a[k]]--;
						break;
					}
					b[a[k]]--;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=0){
				ans[a[j]]++;
				b[a[j]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
