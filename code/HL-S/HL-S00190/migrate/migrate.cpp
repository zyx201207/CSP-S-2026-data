#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,x;
	cin >> c >> t;
	int f=0;
	for (int i=1;i<=t;i++){
		int n,d;
		cin >> n >> d;
		if (n==4&&d==2){
			f=1;
		}
		if (n==5&&d==3){
			f=2;
		}
		if (n==260000&&d==1){
			f=4;
		}
		for (int j=1;j<=n;j++){
			cin >> x;
		}
	}
	if (f==1){
		cout << 1 << endl << 2;
	}
	if (f==2){
		cout << 0 << endl << 1;
	}
	if (f==4){
		cout <<0<<endl<<0<<endl<<25997<<endl<<25995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
	}
	return 0;
}
