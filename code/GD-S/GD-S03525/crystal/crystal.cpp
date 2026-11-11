#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long  jj = m;
	long long  cnt = 0;
	long long ans = 0;
	long long qq;
	long long maxx = -100000;
	
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(&a[1],&a[n+1]);
	if(n>5000){
		for(int i = 1;i<=n;i++){
			c[i] = a[n/2] - a[i];
		}sort(&c[1],&c[n+1]);
		for(int i=1;i<=n;i++){
 			if(c[i]>=0&&jj>=c[i]){
 				cnt++;
 				jj-=c[i];
	 		}
			
		}cout<<cnt;
	}
	for(int j = 2;j<=n;j++){
		cnt = 0;
		jj = m;
		for(int i = 1;i<=n;i++){
			c[i] = a[j]-a[i];
		
		}
	 	sort(&c[1],&c[n+1]);
 		for(int i=1;i<=n;i++){
 			if(c[i]>=0&&jj>=c[i]){
 				cnt++;
 				jj-=c[i];
	 		}else if(c[i]>jj){
	 			cout<<maxx;
	 			return 0;
			 }
			
		}

		maxx = max(maxx,cnt);
		
	}
	
	cout<<maxx;return 0;
	
		
		
	
	
}
