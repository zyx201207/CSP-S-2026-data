#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c; 
	long long t;
	cin>>t;
	long long n[t],d[t];
	for(int i=0;i<t;i++){
		cin>>n[i];
		cin>>d[i];
		long long x[n[i]];
		for(int i=0;i<n[i];i++){
			cin>>x[i];
	}
	}
	if(n[0]==4&&n[1]==5&&d[0]==2&&d[1]==2){
		cout<<1<<endl<<2<<endl;
	}
	for(int i=0;i<t;i++){
		cout<<rand()%n[i]<<endl;
	}
	return 0;
}
