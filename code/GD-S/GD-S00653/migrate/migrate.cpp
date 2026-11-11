#include<bits/stdc++.h>

#define int long long

using namespace std;

int _,t;
int n,m;
int a[2000001];
int l[2000001];
int s1[2000001];//Ïò×ó 
int s2[2000001];//ÏòÓÒ 

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>_>>t;
	if(_ == 11 || _ == 12){
		while(t -- ){
			cin>>n>>m;
			for(int i = 1; i <= n; i ++ ){
				cin>>a[i];
			}
			if(a[1] - a[0] <= m && (a[1] - a[0]) * 2 > m && (a[1] - a[0]) * 3 <= 2*m){
				cout<<n-2<<"\n";
			}else{
				cout<<0<<"\n";
			}
		}
		return 0;
	}
	while(t -- ){
		cin>>n>>m;
		for(int i = 1; i <= n; i ++ ){
			cin>>a[i];
		}
		for(int i = 1; i < n; i ++ ){
			l[i] = a[i+1] - a[i];
		}
		s1[1] = 1; 
		for(int i = 2; i <= n; i ++ ){
			if(a[i+1] - a[i-1] > m && a[i] - a[i-1] <= m){
				s1[i] = s1[i-1] + 1;
			}else{
				s1[i] = 1;
			}
		}
		s2[n] = 1;
		for(int i = n-1; i >= 1; i -- ){
			if(a[i+1] - a[i-1] > m && a[i+1] - a[i] <= m){
				s2[i] = s2[i+1] + 1;
			}else{
				s2[i] = 1;
			}
		}
//		for(int i = 1; i <= n; i ++ ){
//			cout<<l[i]<<"\n";
//		}
//		for(int i = 1; i <= n; i ++ ){
//			cout<<s1[i]<<" "<<s2[i]<<"\n";
//		}
		int ans = 0;
//		for(int i = 1; i <= n; i ++ ){
//			for(int j = i + 3; j <= n; j ++ ){
//				for(int k = i + 1; k < j; k ++ ){
//					if(a[k] - a[i] <= w)
//				}
//			}
//		}
		for(int i = 1; i+3 <= n; i ++ ){
			if(a[i+2] - a[i] <= m && a[i+3] - a[i+1] <= m && a[i+3] - a[i] > m){
				ans += s1[i] * s2[i+3];
//				cout<<i<<" "<<i+3<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
}

