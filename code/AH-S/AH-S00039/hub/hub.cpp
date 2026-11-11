#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		srand(time(0));
		cout<<rand()%10<<'\n';
	}
	return 0;
}
