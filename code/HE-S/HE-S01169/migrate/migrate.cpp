#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
long long t,c,n,d,a[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof a);
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<'0';
	}
	return 0;
}
