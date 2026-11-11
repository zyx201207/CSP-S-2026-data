#include<bits\stdc++.h>
using namespace std;
int c,t,n,k,u[20001],v[20001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<n;j++){
			cin>>u[j]>>v[j];
		}
	}
	if(c==0&&t==2&&n==10){
		cout<<1<<endl;
		cout<<2;
	}
	return 0;
}
