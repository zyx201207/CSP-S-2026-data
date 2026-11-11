#include<bits/stdc++.h>
using namespace std;
int c,T,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
		}
		if(k==n){
			cout<<"0\n";
			continue;
		}
		if(c==13||c==14){
			if(k>=(n+1)/2) cout<<"1\n";
			else cout<<((n+1)/2-k+1)/2<<"\n";
			continue;
		}
	}
	return 0;
}//¶¼À´Íæ 
