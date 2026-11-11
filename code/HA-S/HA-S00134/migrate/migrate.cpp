#include<bits/stdc++.h>
using namespace std;

int c, t;
int n, x[2000001];
long long d;

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (; t--; ) {
		cin>>n>>d;
		for (int i=1;i<=n;i++)
			cin>>x[i];
		if (n==1 || n==2 || n==3) {
			cout<<0<<"\n";
		}
		if (n==4 && x[2]-x[1]<=d && x[4]-x[2]<=d && x[3]-x[1]<=d && x[4]-x[3]<=d) {
			cout<<1<<"\n";
			continue;
		}
		else if (n==4){
			cout<<0<<"\n";
			continue;
		}
		if (n==5) {
			int p=0;
			//cout<<x[2]-x[1]<<" "<<x[4]-x[2]<<" "<<x[3]-x[1]<<" "<<x[4]-x[3]<<" "<<x[4]-x[1];
			//return 0;
			if (x[2]-x[1]<=d && x[4]-x[2]<=d && x[3]-x[1]<=d && x[4]-x[3]<=d && x[4]-x[1]>d)
				p++;
			if (x[5]-x[3]<=d && x[3]-x[2]<=d && x[5]-x[4]<=d && x[4]-x[2]<=d && x[5]-x[2]>d)
				p++;
			if (x[2]-x[1]<=d && x[5]-x[2]<=d && x[3]-x[1]<=d && x[5]-x[3]<=d && (x[5]-x[4]>d || x[4]-x[1]>d))
				p++;
			if (x[4]-x[1]<=d && x[5]-x[4]<=d && x[3]-x[1]<=d && x[5]-x[3]<=d && (x[5]-x[2]>d || x[2]-x[1]>d))
				p++;
			if (x[2]-x[1]<=d && x[5]-x[2]<=d && x[4]-x[1]<=d && x[5]-x[4]<=d && (x[5]-x[3]>d || x[3]-x[1]>d))
				p++;
			cout<<p<<"\n";
			continue;
		}
	}
	return 0;
}
