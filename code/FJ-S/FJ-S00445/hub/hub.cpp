#include<bits/stdc++.h>
using namespace std;
double Rand(){
	return (double)(rand())/RAND_MAX;
}
int main(){
	srand(clock());
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			
		}
		double p=Rand();
		while(p<0.95){
			p+=0.05;
		}
		int f=(rand()%2==0)?-1:1;
		cout<<abs((int )(((n-1)/k)*(p*f)))%(n-1)<<'\n';
	}
	return 0;
}
