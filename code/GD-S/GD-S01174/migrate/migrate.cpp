#include <bits/stdc++.h>
using namespace std;

int a[200010],c,t,n,d;
int b[200010];
void serch(int s){
	if(s>n) return;
	int cnt=0;
	b[s]++;
	while(a[cnt++]<d+a[s]) serch(s+cnt);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int mx=0;
		for(int i=2;i<=n;i++) if(a[i]-a[i-1]>mx) mx=a[i]-a[i-1];
		if(mx==1){
			cout<<n-d-1<<endl;
			continue;
		}
		serch(1);
		for(int i=1+d+1;i<=n;i++) if(b[i]!=1&&b[i]%3==1) cnt++;
//		for(int i=1+d+1;i<=n;i++) cout<<b[i]<<' ';
//		cout<<endl;
		cout<<cnt<<endl;
	}
	return 0;
} 
