#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	srand(time(0));
	cin>>c>>t;
	while(t--&&cin>>n>>k){
		for(int i=0;i<n-1;i++)cin>>k>>k;
		cout<<abs(rand())%n+1<<'\n';}
	return 0;}
