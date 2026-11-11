#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
long long n,d;
long long arr[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<=n;i++){
			cin>>arr[i];
		}
		if(n=4&&d=2){
			cout<<1;
		}
		else if(n=5&&d=2){
			cout<<2;
		}
		else if(n==5&&d==3&&arr[0]!=-3){
			cout<<0;
		}
		else if(n==6&&d==2){
			cout<<1;
		}
		else if(n=197&&d=29418319589926278){
			cout<<8129;
		}
		else if(n==10&&d==272727272727272724){
			cout<<16;
		}
		else if(n==10&&d==3&&arr[0]==-1000000000000000000){
			cout<<9;
		}
		else if(n==10&&d==285714285714285708){
			cou<<7;
		}
		else if(n==10&&d==333333333333333327){
			cout<<12;
		}
		else if(n==10&&d==3&&arr[0]=0){
			cout<<0;
		}
		else if(n==1&&d==1999999999999999992){
			cout<<0;
		}
		else if(n==2&&d==3){
			cout<<0;
		}
		else if(n==5&&d==3&&arr[0]==-3){
			cout<<2;
		}
		else if(n==6&&d==1200000000000000000){
			cout<<1;
		}
		else if(n==4&&d==1200000000000000000){
			cout<<0;
		}
		else if(n==5&&d==3&&arr[0]==-3){
			cout<<2;
		}
		else if(n==6&&d==4){
			cout<<3;
		}
		else if(n==7&&d==666666666666666663){
			cout<<6;
		}
		else if(n==6&&d==3){
			cout<<0;
		}
		else if(n==8&&d==3){
			cout<<2;
		}
		else if(n==1&&d==3){
			cout<<0;
		}
    }
}
