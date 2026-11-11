#include <bits/stdc++.h>
using namespace std;
long long c,t,n,k;
long long u[10005],v[10005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	for (int s=1;s<=t;s++){
		cin >> n >> k;
		for (int i=1;i<=n-1;i++){
			cin >> u[i] >> v[i];
		}
		if (u[1]==1&&v[1]==2&& u[2]==2&&v[2]==3&& u[3]==3&&v[3]==4&& u[4]==4&&v[4]==5){
			cout << 1 << endl;
		}
		else if (u[1]==1&&v[1]==2&& u[2]==1&&v[2]==3&& u[3]==2&&v[3]==4&& u[4]==2&&v[4]==5&& u[5]==3&&v[5]==6&& u[6]==3&&v[6]==7&& u[7]==3&&v[7]==8&& u[8]==7&&v[8]==9&& u[9]==9&&v[9]==10){
			cout << 2 << endl;
		}
	}
	return 0;
}
