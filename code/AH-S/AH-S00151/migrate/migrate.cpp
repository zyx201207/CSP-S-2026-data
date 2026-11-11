#include <bits/stdc++.h>
using namespace std;
const int N=1e7;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof a);
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int maxn=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			maxn=max(maxn,a[i+1]-a[i]);
		}
		if(maxn>=d||n==1){
			cout<<0<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
	return 0;
}
