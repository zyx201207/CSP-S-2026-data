#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,k,minn=0;;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			int b=abs(u-v);
			if(minn>b)minn=b;
		}
		cout<<minn<<"\n";
	}
	return 0;
} 
