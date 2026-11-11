#include<bits/stdc++.h>

using namespace std;

int c,t;
int n,k;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		int ans=0x3f3f3f3f;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int a,b;
			cin>>a>>b;
			ans=min({ans,a,b});
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
