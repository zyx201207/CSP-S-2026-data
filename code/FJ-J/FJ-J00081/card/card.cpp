#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a[500005];
int to[500005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(a[k]==a[j]){
					to[k]=j;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(to[j]!=0) j=to[j];
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
