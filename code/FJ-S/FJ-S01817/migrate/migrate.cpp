#include <bits/stdc++.h>
using namespace std;
int T,n,m,a[2000001],l[2000001],g=1,ans;
bool flag=true;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m;
		cin>>a[1]>>a[2];
		l[1]=a[2]-a[1];
		for(int i=3;i<=n;i++){
			cin>>a[i];
			l[i-1]=a[i]-a[i-1];
			if(l[i-1]!=l[i-2])flag=false;
		}
		if(flag==true){
			cout<<n-2-(m-1)/l[1];
		}
	}
	return 0;
}
/*
6 2
1 2 3 4 5 6
1 1 1 1 1


6 3
1 2 3 6 7 8
1 1 3 1 1
6 2
-4 -3 -2 -1 3 6
1 1 1 4 3
*/
