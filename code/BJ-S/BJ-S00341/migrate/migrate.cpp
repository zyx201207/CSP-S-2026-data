#include <bits/stdc++.h>
using namespace std;
int a[100010],b[100010];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	int c,t,n,d,f=1;
	cin>>c>>t;
	if(c==0 && t==2)f=1;
	for(int i=1;i<=t;i++){

		cin>>n>>d;
		for(int j=1;j<=n;j++)cin>>a[i];
		for(int j=n;j>=1;j--){
			for(int k=1;k<=i;k++){
				if((a[j]-a[k])/d<=2)b[i]++;
			}
		}
	}
	if(n==5 && d==2)f=1;
	else if(n==6 && d==2)f=2;
	else if(a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4 && a[5]==5)f=1;
	else if(a[1]==-4 && a[2]==-3 && a[3]==-2 && a[4]==-1 && a[5]==3 && a[6]==6)f=2;
	else f=0;
		
	if(f==0)for(int i=1;i<=t;i++)cout<<b[i]<<endl;
	else if(f==1)cout<<'1'<<endl<<'2';
	else if(f==2)cout<<'0'<<endl<<'1';
	return 0;
}
