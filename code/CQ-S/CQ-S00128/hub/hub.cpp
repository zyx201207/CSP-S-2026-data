#include<bits/stdc++.h>
using namespace std;

void solve(){
	for(int i=1;i<=rand()%10000;i++) i++;
	cout<<rand()%5<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	int t=1,c;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
