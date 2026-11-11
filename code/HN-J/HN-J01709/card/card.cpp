#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005]; 
int ans[300005];
int table[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int num=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=num;k++){
				if(a[j]==table[k]){
					num=k;
					goto L;
				}
			}
			table[++num]=a[j];
			L:;
		}
		for(int j=1;j<=num;j++){
			ans[table[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
