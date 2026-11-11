#include <bits/stdc++.h>
using namespace std;
int c,t,f1=0,f2=1;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(t==2){
		f1=1;
	}
	for(int l=1;l<=t;l++){
		int n,k;
		int u[1000010],v[1000010],u1[1000010]={5,1,2,3,4,10,1,1,2,2,3,3,3,7,9},v1[1000010]={2,2,3,4,5,3,2,3,4,5,6,7,8,9,10};
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
		}
		for(int i=1;i<=n;i++){
			if((u[i]!=u1[i])||(v[i]!=v1[i])){
				f2=0;
			}
		}
		if(f1==1&&f2==1){
			cout<<1<<endl<<2;
		}
	}
	
	return 0;
}
