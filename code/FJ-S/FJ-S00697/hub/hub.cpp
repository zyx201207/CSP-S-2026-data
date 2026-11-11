#include<bits/stdc++.h>
using namespace std;
long long c,t,n,g;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	c+=1;
	while(c--){
		while(t--){
			cin>>n>>g;
			cout<<rand()%n;
		}
	}
	return 0;
} 
