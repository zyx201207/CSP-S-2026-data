#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n-3;i++){
			if(d<x[i+3]-x[i]&&x[i+3]-x[i+2]<d&&x[i+2]-x[i+1]<d&&x[i+1]-x[i]<d){
				cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
}
