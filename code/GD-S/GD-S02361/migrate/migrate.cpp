#include<bits/stdc++.h>
using namespace std;

long long c,t;
long long n,m;
long long a[2000010];
long long pre[2000010];
long long tot;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			pre[i]=a[i]-a[i-1];
		}
		pre[1]=0;
		if(m!=2){
			cout<<0<<"\n";
			continue;
		}
		for(int i=2;i+m<=n;i++){
			if(pre[i]<=m && pre[i+1]<=m && pre[i+2]<=m) tot++;
		}
		cout<<tot<<"\n";
		tot=0;
	}
	return 0;
}
