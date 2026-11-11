#include<bits/stdc++.h>
using namespace std;
int n,m;
int d[200005],c[200005];
int cnt[2000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>d[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) c[j]=d[j];
		for(int j=i;j<=n;j++){
			for(int k=i;k<=j-1;k++){
				if(d[k]==d[j]){
					for(int r=k;r<=j-1;r++) c[r]=0;
				}
			}
		}
		for(int j=i;j<=n;j++){
				cnt[c[j]]++;
			}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
/*

*/
