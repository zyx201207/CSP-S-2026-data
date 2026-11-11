#include<bits/stdc++.h>
using namespace std;

int main(){

	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//		
//	
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	int c,t;cin >>c >>  t;
	while(t--){
	
	int n,d;cin >> n >> d;
	
	int arr[n+10];int dt=0,flag = 1;arr[0] = 0;
	for(int i = 1;i <= n;i++) {
		cin >> arr[i];
		if(i <= 2){
			dt = arr[i]-arr[i-1];
		}else{
			if(dt != arr[i]-arr[i-1]){
				flag = 0;
			}
		}
	}
	if(c == 11 or c == 12){
		if(dt > d){
			cout << 0 << endl;
			continue;
		}else{
			if(floor(d/dt)){
				cout << ceil((n-1)/2) << endl;
			} else{
				cout << 0 << endl;	
			}
			
			
		}
		
	}else{
		
		
		
		
		
		
	}
	
	
}
	return 0;
} 
