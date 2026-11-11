#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[50005],ex[50005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			x[i]=0;
			ex[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int cnt=0;
		for(int i=1;i<n;i++){
			ex[i]=x[i+1]-x[i]; 
			if(ex[i]==ex[i-1]) cnt++;
		} 
		if(cnt==n-2){
			cout<<2;
			continue;
		}
		cout<<1;
	}
	
	return 0;
}
