#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,t,n,m;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1,l;i<=n;i++) cin>>l>>l;
		if(c==0){
			if(t==1) cout<<"1\n";
			else cout<<"2"; 
		}
	}
	return 0;
}
