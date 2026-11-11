#include<bits/stdc++.h>
using namespace std;
int a[500010],ans[300010],b[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,it=1,tt=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(m--){
		for(int i=tt;i<=n;i++){
			for(int j=1;j<=it;j++){
				if(a[i]==b[j]){
					for(int k=j;k<=i-1;k++){
						b[k]=0;
					}
					b[j]=a[i];
					it=it-i+1;
				}
			}
			b[it]=a[i];
			it++;
		}
		it--;
		for(int j=1;j<=m;j++){
			for(int i=1;i<=it;i++){
				if(b[i]==j){
					ans[j]++;
				}
			}
		}
		tt++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
/*
in:4 3
1 2 1 3

out:
*/
