#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200005];
	int ans = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j = i+1;j<n;j++){
			int k = 0,q = 0;
			while(a[i]!=0 && a[j]!=0){
				if(a[i]%2 == 1 && a[j]%2==1){
					q = q+2^k;
				}
				k++;
				a[i] = a[i]/2;
				a[j] = a[j]/2;
			}
			if(q>ans){
				ans = q;
			}
		}
	}

	cout<<ans;
	
	
	
	return 0;
}
