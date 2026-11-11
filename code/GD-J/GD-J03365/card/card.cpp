#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[300005];
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];	
    }
    for (int i=1;i<=m;i++){
    	for (int j=i;j<=n;j++){
    		if (a[j]==i){
    			sum[i]++;
			}
		}
	}
    for (int i=1;i<=m;i++){
    	cout<<sum[i]<<" ";
	}
	
	return 0;
}
