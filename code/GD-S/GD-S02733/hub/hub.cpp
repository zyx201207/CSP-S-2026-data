#include<iostream>
using namespace std;
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
		}
		int num=(n-k)/4;
		if((n-k)%4!=0)num++;
		cout<<num+1<<'\n';
	}
	return 0;
}
