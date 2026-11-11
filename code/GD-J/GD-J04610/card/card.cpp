#include <bits/stdc++.h> 
using namespace std;
int sum[20], ll[20];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "W", stdout);
	int n, m, l[600];
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>l[i];
		if(sum[l[i]]==0)
			sum[l[i]]++;
		else {
			int j=i-1;
			while(l[i]!=l[j]){
				sum[l[j]]--;
			}
		}
		for(int i=0; i<=l[i]; i++){
			if(sum[i]==1){
				ll[i]++;
			}
		}
	}
	
	for(int i=1; i<=m; i++){
			cout<<ll[i];
	}
	return 0;
}
