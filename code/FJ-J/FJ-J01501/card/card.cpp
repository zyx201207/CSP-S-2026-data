#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a[512345], zm[512345], ans[312345];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout); 
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	int ls=1;
	while(ls<=n){
		for(int i=1; i<=n; i++) zm[i]=0;
		int r=0;
		for(int i=ls; i<=n; i++){
			bool flag=true;
			int l=-1;
			for(int j=1; j<=r; j++){
				if(zm[j]==a[i]){
					l=j;
					flag=false;
					break;
				}
			}
			if(l!=-1){
				for(int j=l; j<=r; j++) zm[j]=0;
				r=l;
				zm[r]=a[i];
			}
			if(flag) zm[++r]=a[i];
		}
		for(int i=1; i<=r; i++){
			ans[zm[i]]++;
		}
		ls++;
	}
	for(int i=1; i<=m; i++) printf("%d ", ans[i]);
	return 0;
}
