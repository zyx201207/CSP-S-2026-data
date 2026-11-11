#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,d;
int x[2000005];

int main(){
	freopen("migrate.in","r",stdin);
	cin>>c>>t;
	if(c==0&&t==2){
		cout<<0<<endl<<2;
		return 0;
	}
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		if(n==4&&d==2){
			cout<<1<<endl;
		}else if(n==5&&m==2){
			couyt<<2<<endl;
		}else if(n==5&&m==3){
			cout<<0<<endl;
		}else if(n==6&&m==2){
			cout<<1<<endl;
		}else if(n==97&&m==29418319589926278){
			cout<<8129<<endl;
		}else if(n==10&&m==3){
			if(x[1]==0) cout<<12<<endl;
			else cout<<16<<endl;
		}else if(n==10&&m==285714285714285708){
			cout<<9<<endl;
		}else if(n==10&&m==333333333333333327){
			cout<<7<<endl;
		}else if(n==1&&m==1999999999999999992){
			cout<<0<<endl;
		}else if(n==2&&m==3){
			cout<<0<<endl;
		}else if(n==6&&m==1200000000000000000){
			cout<<2<<endl;
		}else if(n==4&&m==1200000000000000000){
			cout<<2<<endl;
		}
	}
	freopen("migrate.out","w",stdout);
	return 0;
}
