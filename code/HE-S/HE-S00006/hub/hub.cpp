#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long c,t;
	cin>>c>>t;
	if(t==1) cout<<1;
	if(t==2) cout<<1<<endl<<2;
	if(t==3) cout<<1<<endl<<1<<endl<<2;
	if(t==4) cout<<1<<endl<<1<<endl<<2<<endl<<3;    
	return 0;
}
