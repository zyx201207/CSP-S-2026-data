#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+6;
long long n,a[N],c,T,s[N],d;
void solve_1(){
	int sum=0;
	for(int i=1;i<=n;i++) s[i]=a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j-i<3) continue;
			if(s[j]-s[i]>=2*d) continue;
			if(s[j]-s[i]<=d) continue;
			int o=0;
			for(int k=i+1;k<=j-1;k++){
				if(s[k]-s[i]<=d&&s[j]-s[k]<=d) 
				o++;
			}
			if(o==2) sum++;
//			if(o==2) cout<<i<<' '<<j<<"\n";
		}
	} cout<<sum<<"\n";
}
void solve_2(){
	int sum=0,p=0;
	for(int i=1;i<=n;i++) s[i]=a[i];
	p=a[2]-a[1];
	if(p==0) {
		cout<<0<<"\n";
		return ;
	}
	int u=d/p;
	if(u<2) {
		cout<<0<<"\n";
		return ;
	}
	if(n-u-1<0){
		cout<<0<<"\n";
		return ;
	}
//	cout<<u<<' '<<p<<' '<<d-1<<' '<<n<<"PPP\n";
	cout<<n-u-1<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
//		cout<<d<<"OIOII\n";
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]); //cout<<c;
		if(c<=10) {
			solve_1();
		}
		if(c==11||c==12){
			solve_2();
		}
	}
	return 0;
} 

