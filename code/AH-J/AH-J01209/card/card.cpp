#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[300001],c[500001],ans[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	fill(c+1,c+n+1,1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=0){
				for(int k=b[a[j]];k<=j-1;k++){
					b[a[k]]=0;
					c[k]=0;
				}
			}
			b[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(c[j]==1)
				ans[a[j]]++;
		}
		fill(b+1,b+m+1,0);
		fill(c+1,c+n+1,1);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
