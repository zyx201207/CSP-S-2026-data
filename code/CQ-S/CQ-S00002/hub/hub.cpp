#include<bits/stdc++.h>
using namespace std;
long long sss,t,a;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>sss>>t;
	for(int i=1;i<=t;i++){
		long long x,y;
		cin>>x>>y;
		for(int j=1;j<=x*2-2;j++){
			cin>>a;
		}
		cout<<x/y-1<<endl;
	}
	return 0;
} 

