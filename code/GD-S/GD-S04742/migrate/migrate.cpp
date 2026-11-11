#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d,a[2000060];
int solve(){
	cin>>n>>d;
	int m=n;
	memset(a,0,sizeof a);
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[2]-a[1]==a[3]-a[2]){
		int q=a[2]-a[1];
		if(d<q) return 0;
		else if(d/q==1) return 0;
	}
	return 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t; 
	while(t--) cout<<solve()<<"\n";
	return 0;
}

