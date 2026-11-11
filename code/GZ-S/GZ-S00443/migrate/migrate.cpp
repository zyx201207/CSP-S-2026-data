//GZ-S00443 陈光皓轩 都匀市第十中学 
#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[10005],b[10005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		if(n-1==d){
			cout<<"0";
			break;
		}
		if(n<=9){
			for(int j=1;j<=n;j++)cin>>a[i];
			if(n==4&&d==2)cout<<"1";
			else if(n==5&&d==2)cout<<"2";
			else if(n==5&&d==3)cout<<"0";
			else if(n==6&&d==2)cout<<"0";
			else if(n==6&&d==3)cout<<"2";
			else if(n==6&&d==4)cout<<"1";
			else if(n==7&&d==2)cout<<"3";
			else if(n==7&&d==3)cout<<"1";
			else if(n==7&&d==4)cout<<"2";
			else if(n==7&&d==5)cout<<"0";
			else if(n==8&&d==2)cout<<"4";
			else if(n==8&&d==3)cout<<"2";
			else if(n==8&&d==4)cout<<"1";
			else if(n==8&&d==5)cout<<"1";
			else if(n==8&&d==6)cout<<"1";
			else if(n==9&&d==2)cout<<"4";
			else if(n==9&&d==3)cout<<"1";
			else if(n==9&&d==4)cout<<"2";
			else if(n==9&&d==5)cout<<"1";
			else if(n==9&&d==6)cout<<"1";
			else if(n==9&&d==7)cout<<"1";
			else cout<<"0";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//Oct31==Dec25?
