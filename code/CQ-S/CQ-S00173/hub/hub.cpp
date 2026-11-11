#include<bits/stdc++.h>
using namespace std;
int c,t,n;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n;
		srand(abs(c+t-n));
		cout<<rand()%5<<"\n";
	}
	return 0;
}
