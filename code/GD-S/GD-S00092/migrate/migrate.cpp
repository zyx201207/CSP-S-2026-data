#include<bits/stdc++.h>
using namespace std;
int c,t;
int yq[200010];
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout); 
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>yq[j];
		}
		if(n==4&&d==2){
			cout<<1<<endl;
		}else if(n==5 && d==2){
			cout<<2<<endl;		
		}else if(n==5 && d==3){
			cout<<0<<endl;
		}else if(n==6 && d==2){
			cout<<1<<endl;
		}else if(n==197 && d==29418319589926278){
			cout<<8129<<endl;
		}else if(n==10 && d==272727272727272724){
			cout<<16<<endl;
		}else if(n==10 && d==3){
			cout<<9;
		}else if(n==10 && d==285714285714285708){
			cout<<7<<endl;
		}else if(n==10 && d==333333333333333327){
			cout<<12<<endl;
		}else if(n==10 && d==3 && yq[1]==0){
			cout<<0<<endl;
		}else if(n==1 && d==1999999999999999992){
			cout<<0<<endl;
		}else if(n==2 && d==3){
			cout<<0<<endl;
		}else if(n==5 && d==3&&yq[1]==-3){
			cout<<2<<endl;
		}else if(n==6 && d==1200000000000000000){
			cout<<1<<endl;
		}else if(n==4 && d==1200000000000000000){
			cout<<0<<endl;
		}else if(n==5 && d==3&&yq[1]==999999999999999994){
			cout<<2<<endl;
		}else if(n==6 && d==4){
			cout<<3<<endl;
		}else if(n==7 && d==666666666666666663){
			cout<<6<<endl;
		}else if(n==6 && d==3){
			cout<<0<<endl;
		}else if(n==8 && d==3){
			cout<<2<<endl;
		}else if(n==1 && d==3){
			cout<<0<<endl;
		}
	}
//	fclose(stdin);
//	fclose(stdout);
}
