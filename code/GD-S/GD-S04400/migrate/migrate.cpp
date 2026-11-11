#include <bits/stdc++.h>
using namespace std;
int c,t;
int a[200010];
void solve(){
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==1){
		cout<<0<<endl;
		return;
	}
	int cha=a[2]-a[1];
	if(d<2*cha||a[n]<=d){
		cout<<0<<endl;
		return;
	}
	int end=n-d/cha;
	cout<<end-1<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) solve();
	return 0;
}
