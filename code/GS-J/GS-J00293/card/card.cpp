#include <bits/stdc++.h>
using namespace std;
int m,n,a[1000005];
map<int,int> mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int q[n+5][1000005]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=n-i+1;j>=1;j--){
			q[i][j]=a[j];
			for(int k=n-i-1;k>=1;k--){
				if(q[i][k]=a[i]){
					q[i][k]=a[i];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=n-i+1;j>=1;j--){
			if(q[i][j]=i){
				mp[i]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<mp[i];
	}
	return 0;
}
