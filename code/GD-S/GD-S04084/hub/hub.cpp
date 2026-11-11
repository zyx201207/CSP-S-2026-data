#include<bits/stdc++.h>
using namespace std;
using ll= long long ;
const int N = 5e5+5;
ll c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	cin>>c>>t;
	while(t--){
		cin>>n>>k;	
		cout<<rand()%n;
	}
	return 0;
}
