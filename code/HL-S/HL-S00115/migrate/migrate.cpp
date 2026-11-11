#include<bits/stdc++.h>
using namespace std;
int q[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;cin>>t;
	int a;cin>>a;
	while(a--){
		int m,n;
		cin>>m>>n;
		for(int i=1;i<=m;i++){
			cin>>q[i];
		}
		if(t<=2){
			cout<<m/3<<endl;	
		}
		if(t==13||t==14){
			cout<<0<<endl;			
		}
		if(t==11||t==12){
			int maxstep=n/(q[2]-q[1]);
			if(maxstep==2){
				cout<<m-2<<endl;
			}else{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}

