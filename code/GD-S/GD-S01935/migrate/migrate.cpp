#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,TT=200;
typedef long long ll;
int C,t,n,d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>t;
	if(C<=2){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j){
				if(a[j]-a[i]<=d);
			}
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
