#include<bits/stdc++.h>
using namespace std;
int n,k,c,v[1000005],u[1000005];
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>v[i]>>u[i];
	}
	if(n==k){
		cout<<0<<"\n";
		return ;
	}
	if(c==13||c==14){
		int m=n/2;
		if(k>=m){
			cout<<1<<"\n";
			return ;
		}
		int k1=(k+1)/2,k2=k/2;
		int m1=m/2,m2=(m+1)/2;
		cout<<max((m2-k1+1)/2+1,(m1-k2+1)/2+1)<<"\n";
		return ;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
