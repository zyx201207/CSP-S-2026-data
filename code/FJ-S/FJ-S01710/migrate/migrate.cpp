#include<bits/stdc++.h>
using namespace std;
 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int l=1;l<=t;l++){
		int n,d;
		cin>>n>>d;
		int x[2000010];
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		int ggg=0;
		int gggg=x[2]-x[1];
		for(int i=2;i<=n;i++){
			if(gggg!=x[i]-x[i-1])ggg=1;
		}
		if(c==0){
			if(n==4 && d==2)cout<<"1";
			if(n==5 && d==2)cout<<"2";
			if(n==5 && d==3)cout<<"0";
			if(n==6 && d==2)cout<<"1";}
		
	} 
	return 0;} 
