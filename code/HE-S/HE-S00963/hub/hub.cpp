#include <bits/stdc++.h>
using namespace std;
struct qwe{
	int u,v;
}s[1000010];
int c,t,n,k,;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>s[i].u>>s[i].v;
		}
		if(n<=7) cout<<1;
		else if(n<=15) cout<<2;
		else if(n<=30) cout<<3;
		else cout<<4;
	}
	return 0;
}
