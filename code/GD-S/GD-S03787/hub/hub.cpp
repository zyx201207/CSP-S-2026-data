#include<bits/stdc++.h>
using namespace std;
//hub
void work(){
	int n,k,a,b;
	cin>>n>>k;
	for(int i=1;i<n;i++)cin>>a>>b;
	if(k==n){
		cout<<n<<endl;
		return;
	}
	n=(n-1)/2+2;
	n=(n+1)/2;
	if(k==1 && n!=1){
		cout<<n<<endl;
		return; 
	}else{
		k/=2;
		if(n&1){
			n-=1;
			k-=1;
		}
		cout<<n/2-k/2<<endl; 
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		work();
	}
	return 0;
}

