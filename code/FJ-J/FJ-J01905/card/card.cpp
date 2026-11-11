#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10,M=3*1e5+10;
int n,m,a[N],b[N],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			ans[a[j]]++;
			for(int k=j-1;k>=i;k--){
				if(b[j]==b[k]){
					for(int l=k;l<j;l++){
						if(b[l]){
							ans[b[l]]--;
							b[l]=0;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
