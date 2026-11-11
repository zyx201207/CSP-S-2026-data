#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k,cnt=0;
	int u[10000005],v[10000005];
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		cnt++;
		for(int j=1;j<=n;j++){
			cin>>u[j]>>v[j];
		}
		for(int q=1;q<=n;q++){
			if(q==cnt){
		        cout<<k-1;
	        }
		}
	}
	return 0;
} 
