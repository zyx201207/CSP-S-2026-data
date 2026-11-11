#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int c[300005]={0};
		for(int j=i;j<=n;j++){
			if(c[a[j]]!=0){
				for(int k=c[a[j]];k<=j;k++){
					c[a[k]]=0;
				}
			}
			c[a[j]]=j;
		}
		for(int i=1;i<=m;i++){
			if(c[i]!=0) b[i]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
	return 0;
} 

