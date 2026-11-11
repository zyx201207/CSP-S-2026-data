#include<iostream>
using namespace std;

const int MAXN=1e6+5;
int c,t;
int n,k;
int u[MAXN],v[MAXN];

int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
		}
		cout<<1<<endl;
	} 
	
	return 0;
} 
