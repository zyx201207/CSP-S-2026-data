#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int c[500005],v=0;
		for(int j=i;j<=n;j++){
			c[++v]=a[j];
			for(int l=v-1;l>=1;l--){
				if(c[l]==c[v]){
					v=l;break;
				}
			}
		}
		for(int l=1;l<=v;l++){
			b[c[l]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
