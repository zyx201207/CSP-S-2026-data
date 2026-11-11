#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	cin>>c>>t;
	while(t--){
		int x=rand()%10;
		cout<<x<<"\n";
	}
	return 0;
}
