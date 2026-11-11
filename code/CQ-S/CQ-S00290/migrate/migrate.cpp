#include <bits/stdc++.h>
using namespace std;
int cc,T;
int n,d;
int a[1006];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cc>>T;
	while(T--){
//		cout<<T<<':';
		cin>>n>>d;
		int dd=0;
		bool ddd=1;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			if(i==2){
				dd=a[i]-a[i-1];
			}
			if(i>2&&a[i]-a[i-1]!=dd)ddd=0;
		}
		ddd=1;
		if(ddd){
			int mm=d/dd;
			int m=mm*2;
			cout<<n-m+1;
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


*/
