#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000005],b[10000005],ans[10000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		for(int j=i;j>=1;j--){
			if(b[i]==b[j]){
				for(int k=j;k<i;k++) b[k]=0;
			}
		}
	}for(int j=1;j<=n;j++) ans[b[j]]++;
	for(int o=2;o<=n;o++){
		for(int i=o;i<=n;i++){
			b[i]=a[i];
			for(int j=i;j>=1;j--){
				if(b[i]==b[j]){
					for(int k=j;k<i;k++) b[k]=0;
				}
			}
		}for(int j=o;j<=n;j++) ans[b[j]]++;
	}for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
