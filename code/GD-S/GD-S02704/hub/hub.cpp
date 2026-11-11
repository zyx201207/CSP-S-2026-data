#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while (t--){
		if (rand()%2==1){
			cout<<1<<"\n";
		}else{
			cout<<2<<"\n";
		}
	}
	return 0;
}
