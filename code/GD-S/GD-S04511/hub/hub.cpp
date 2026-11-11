#include<bits/stdc++.h>
using namespace std;
const int N=5e3+7;
int c,t,n,k,s;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		s=(n+1)/2+1;
		if(k>1)cout<<(s+3-k)/4<<"\n";
		else cout<<s/2<<"\n";
	}
	return 0;
}
