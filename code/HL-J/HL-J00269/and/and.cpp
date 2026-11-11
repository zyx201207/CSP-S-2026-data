#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int maxn;
	int max1,max2;
	int a[1000] = {};
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	
	for(int j = 1;j <= n;j++){
	
	}
	if(m = 1){
		for(int g = 1;g <= n;g++){
			if(a[g - 1] < a[g]){
				maxn = a[g];
			}
		}
			
	if(m = 2){
		for(int k = 1;k <= n;k++){
			if(a[k - 1]&&a[k] < a[k]&&a[k + 1]){
				maxn = a[k + 1]&&a[k];
			}
			}
		}
	}
	
	
	cout<<maxn;
	
	return 0;

}
