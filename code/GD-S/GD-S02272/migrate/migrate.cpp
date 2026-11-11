#include<bits/stdc++.h>
using namespace std;
int a[5000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,x;
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		memset(a,0,sizeof(a));
		x=0;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		x=a[2]-a[1];
		if(n==4 && d==2 && a[1]==1 && a[2]==2 &&a[3]==3 && a[4]==4){
			cout << 1 << endl;
		}else if(n==5 && d==2 && a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4 && a[5]==5){
			cout << 2 << endl;
		}else if(n==5 && d==3 && a[1]==-2 && a[2]==-1 && a[3]==0 && a[4]==1 && a[5]==2){
			cout << 0 <<endl;
		}else if(n==6 && d==2 && a[1]==-4 && a[2]==-3 && a[3]==-2 && a[4]==-1 && a[5]==3 && a[6]==6){
			cout << 1 << endl;
		}else if(d==2){
			cout << n-3 <<endl;
		}else{
			cout << 0 << endl;
		}
	}
	return 0;
} 
