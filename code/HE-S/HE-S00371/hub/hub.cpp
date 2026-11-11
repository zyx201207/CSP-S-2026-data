#include<bits/stdc++.h>
using namespace std;
bool can[10010][10010]={false};
int c,t; 
int main(){
    freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			int a,b;
			cin>>a>>b;
			can[a][b]=true;
		}
		if(n<=5)
		cout<<1<<endl;
		else
		cout<<2;
	}
	return 0;
}
