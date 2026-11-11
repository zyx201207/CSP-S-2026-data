#include<bits/stdc++.h>
using namespace std;



int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//		
//	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	long long n,m,cnt = 0;
	cin >> n >> m;

	 long long arr[n+10],sum[n+10];
	 arr[0] = 0;sum[0] = 0;
	 for(int i = 1;i <= n;i++){
	 	
	 	cin >>arr[i];
	 	
	 }
	 
		sort(arr+1,arr+n+1);
	 
	 long long c = 0;long long ans = 1,res = 1;
	 for(int i = 1;i <= n;i++){
	 	sum[i] = arr[i]-arr[1];
		}
	 for(int l = 2,r = 2;l <= n && r <= n;){
	 	
	 		if(c <= m){
	 			while(c <= m and r <= n){
	 				r++;c+=sum[r];
	 				if(arr[r] == arr[r-1]){
	 					c-=sum[r];
					 } 
	 				res++;
				 }
				 ans = max(res,ans);
			 }
			 if(c > m){
			 	
			 	while(c > m and r <= n and l <= n){
			 		l++;c-=sum[l];
			 		if(arr[l] == arr[l-1]){
					 c+=sum[l];}
			 		res--;
				 }
			 	
			 	ans = max(ans,res);
			 	
			 }
	 	
	 	
	 	}
	 
	cout << ans;
	
	
	
	return 0;
} 
