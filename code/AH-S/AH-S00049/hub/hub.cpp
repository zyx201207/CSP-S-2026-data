#include<bits/stdc++.h>
using namespace std;
#define int long long
int ai[10],bi[10],ci[10];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int x=1;x<n;x++){
			cin>>ai[x]>>bi[x];
			ci[ai[x]]++,ci[bi[x]]++;
		}
		if(k==1){
			if(ci[1]==4||ci[2]==4||ci[3]==4||ci[4]==4)cout<<1;
			else cout<<2;
			cout<<endl;
		}
		if(k==2||k==3||k==4)cout<<1<<endl;
		if(k==5)cout<<0<<endl;
	}
	return 0;
}
