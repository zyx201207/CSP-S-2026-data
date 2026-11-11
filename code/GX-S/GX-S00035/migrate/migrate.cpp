#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	int ans[t];
	for(int k=0;k<t;k++){
		int s=0;
		cin>>n>>d;
		int w[n];
		for(int i=0;i<n;i++) {cin>>w[i];}
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(w[j]-w[i]==d+1 && j-i!=1 && j-i<4) s++;
			}
		}
		ans[k]=s;
	}
	for(auto x:ans) cout<<x<<"\n";
	return 0;
}
