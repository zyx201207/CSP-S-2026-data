#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
long long n,d;
long long a[N];
long long s[N];
void solve1(){
	long long l=s[n];
	long long maxx=d/l;
	if(maxx>n/2||maxx<=1){
		cout<<0<<endl;
		return;
	}
	cout<<n-(2*maxx)+1<<endl;
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		a[0]=0;
		for(int i=1;i<=n;i++) s[i]=a[i]-a[i-1];
		int f=0;
		for(int i=3;i<=n;i++) if(s[i]!=s[i-1]){
			f=1;
			break;
		}
		if(n<=3){
			cout<<0<<endl;
			continue;
		}
		if(f==0) solve1();
	}
	return 0;
}
