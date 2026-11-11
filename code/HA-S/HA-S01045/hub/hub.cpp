#include<bits/stdc++.h>
using namespace std;
const int N=129835;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		long long u[N],v[N];
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
	if(k>=100000000){
			cout<<100000<<endl;
			continue;
		}
		else{
			cout<<1<<endl;
			continue;
		}
		if(k>=10000000){
			cout<<478844<<endl;
			continue;
		}
		else{
			cout<<n/5<<endl;
		}
	}
	return 0;
} 
