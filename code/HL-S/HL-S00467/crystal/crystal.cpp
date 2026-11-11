#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b=n+100;
	int a[b];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		while(m!=0){
			for(int j=2;j<=n;j++){
				if(a[i]+m==a[j]){
					ans++;
				}	
			}
			
			m--;
		}
	}
	cout<<ans;
	return 0;
}