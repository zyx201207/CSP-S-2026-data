#include <bits/stdc++.h>
using namespace std;
int arr[2123456]={};
int absarr[2123456]={};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for(int j=1;j<=t;j++){
		
		int n,d;
		int ans=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> arr[i];
		}

	
		for(int i=1;i<=n;i++){
			absarr[i]=abs(arr[i]);	
		}
		for(int i=1;i<=n;i++){
			for(int k=n;k>=i;k--){
				if((abs(absarr[k]-absarr[i])==3) && (arr[k]-arr[k-1]<=d)) ans++;
			}	
		}			
		cout << ans << endl;
		for(int i=1;i<=n;i++){
			arr[i]=0;
		}
	}
	
	return 0;
}
