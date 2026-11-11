#include <bits/stdc++.h>
using namespace std;
intg c,t,n,k,maxx=0;
int u[10005]={0},v[10005]={0};
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		cin >> n >> k;
		for(int j=1;j<n;j++){
			cin >> u[j] >> v[j];
		} 
		for(int m=1;m<n;m++){
			if(u[i]-v[i]>0){
				maxx=max(maxx,u[i]-v[i]);
			}else{
				maxx=max(maxx,v[i]-u[i]);
			}
		}
		cout << maxx;
		maxx=0;\
	}
	return 0;
}
