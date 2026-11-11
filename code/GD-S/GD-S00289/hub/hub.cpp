#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//hug
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++) {
		srand(time(0)*i);
		cout<<rand()%2<<"\n";
	}
	
	//never AFO 
	return 0;
}
