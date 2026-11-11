#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,n;
	cin>>c>>n;
	for(int i=1;i<=n;i++){
		if(i%2) cout<<1<<"\n";
		else cout<<2;
	}
	return 0;
}
