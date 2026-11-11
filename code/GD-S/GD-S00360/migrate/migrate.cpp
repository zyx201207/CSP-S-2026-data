#include <bits/stdc++.h>
using namespace std;
int a[1000001];
	int n,d;
bool check(int x,int y){
	if(y-x==3) return 1;
	return 0;
}
int main(){
	int c,t;
	cin>>c>>t;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int i=1;i<n-1;i++){
			for(int j=i+2;j<=n;j++){
				if(check(i,j)) ans++;
			}
		}
		cout<<ans<<"\n";
	}
}}
