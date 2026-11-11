#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,c;
	cin>>c>>t;
	if(c==13||c==14) for(int i=1;i<=t;i++) cout<<i<<endl;
	else{
		srand(time(NULL));
		for(int i=1;i<=t;i++) cout<<rand()*i%t<<endl;
	}
	return 0;
} 
