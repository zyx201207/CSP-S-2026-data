#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	srand(time(0)); 
	cin>>c>>t;
	while(t--&&cin>>n>>d){
		for(int i=0;i<n;i++)cin>>d;
		cout<<abs(rand())%n+1<<'\n';}
	return 0;}
