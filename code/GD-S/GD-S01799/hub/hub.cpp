#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,k,x,y;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>x>>y;
		}
		cout<<k/2+1<<endl;
	}
	return 0;
} 
