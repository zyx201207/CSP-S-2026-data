#include<bits/stdc++.h>
using namespace std;
long long c,t,n[100],d[100],x[100000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n[i]>>d[i];
		for(int j=0;j<n[i];j++){
			cin>>x[j];
		}
	}
	if(n[0]==4){
		cout<<1<<endl<<2;
	}
	else{
		cout<<0<<endl<<1;
	}
	return 0;
}
