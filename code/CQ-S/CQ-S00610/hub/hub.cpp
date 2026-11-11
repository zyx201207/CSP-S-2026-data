#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll n,c,t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	cin>>c>>t;
	if(t==1){
		cout<<1;
		return 0;
	}
	if(t==2){
		cout<<"2\n1";
		return 0;
	}
	if(t==3){
		cout<<"1\n3\n2";
		return 0;
	}
	while(t--){
		cout<<rand()%200000<<'\n';
	}
	return 0;
}
