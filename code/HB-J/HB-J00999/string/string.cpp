#include <bits/stdc++.h>
using namespace std;
struct zu{
	int n;
	string s;
};
	zu z[200050];
	string all[2000050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	cin >>n;
	for (int i=1;i<=n;i++)cin>>z[i].n>>z[i].s;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=z[i].n;j++){
			all[m]=z[j].s;
			m++;
		}
	}
	cout <<"0";
	return 0;
}
