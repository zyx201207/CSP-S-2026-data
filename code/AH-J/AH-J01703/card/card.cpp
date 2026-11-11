#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],zh[2000020],tl,ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		tl=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				while(zh[tl]!=a[j]){
					b[zh[tl]]--;
					tl--;
				}
				b[zh[tl]]--;
				tl--;
			}
			zh[++tl]=a[j];
			b[zh[tl]]++;
		}
		for(int i=1;i<=m;i++){
			if(b[i]){
				ans[i]++;
				b[i]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
