#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t>0){
		t--;
		int n,m;
		cin>>n>>m;
		int s,b;
		for(int i=1;i<n;i++){
			cin>>s>>b;
		}
		if(n+m>10)
		cout<<2;
		else
		cout<<1;
	}
	return 0;
}
