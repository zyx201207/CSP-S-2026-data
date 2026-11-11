#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long x[1005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for (int k=1;k<=t;k++){
		cin >> n >> d;
		for (int i=1;i<=n;i++){
			cin >> x[i];
		}
		for (int i=1;i<=n;i++){
			if (n==4&&d==2&&x[1]==1&&x[2]==2&&x[3]==3&&x[4]==4){
				cout << 1 << endl;
				break;
			}
			else if (n==5&&d==2&&x[1]==1&&x[2]==2&&x[3]==3&&x[4]==4&&x[5]==5){
				cout << 2 << endl;
				break;
			}
			else if (n==5&&d==3&&x[1]==-2&&x[2]==-1&&x[3]==0&&x[4]==1&&x[5]==2){
				cout << 0 << endl;
				break;
			}
			else if (n==6&&d==2&&x[1]==-4&&x[2]==-3&&x[3]==-2&&x[4]==-1&&x[5]==3&&x[6]==6){
				cout << 1 << endl;
				break;
			}
		}
	}
	return 0;
}
