#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

ll lg(int a){
	int p;
	while(a){
		a>>=1;
		p++;
	}
	return p;
}

ll c,t,town,hub,x[1000009],y[1000009];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	for(int z=0;z<t;z++){
		
		memset(x,0,sizeof(x));
		memset(x,0,sizeof(x));
		cin>>town>>hub;
		for(int i=0;i<town-1;i++) cin>>x[i]>>y[i];
		cout<<(int)lg(town)/2;
		
		
		
	}
}
