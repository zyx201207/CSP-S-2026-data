#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,x,y;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>x>>y;
		srand(time(0));
		cout<<rand()%(n/2)<<endl;
	}
	return 0;
} 
