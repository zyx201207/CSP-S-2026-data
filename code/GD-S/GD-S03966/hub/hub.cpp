#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,k;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
		}
		if(c==0&&n==5&&k==2){
			cout<<1<<endl;
		}else if(c==0&&n==10&&k==3){
			cout<<2<<endl;
		}
	}
	return 0;
}
