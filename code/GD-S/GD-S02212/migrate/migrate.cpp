#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for(int ti=1;ti<=t;ti++){
		int n,d;
		cin >> n >> d;
		int x[n+1];
		int weth[n+1]={};
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[j-1]<=d){
					weth[j]++;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(weth[i]>=2){
				ans++;
			}
		}
		cout << (ans+1)/d << endl;
	}
	return 0;
} 
