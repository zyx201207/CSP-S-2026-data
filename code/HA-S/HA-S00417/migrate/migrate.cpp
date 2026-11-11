#include<bits/stdc++.h>
using namespace std;
int no_ce,t,n;
long long d;
const int N=2e6+5;
long long a[N];
bool isd(char c){
	return ('0'<=c&&c<='9');
}
inline long long read(){
	long long i=0,f=1;
	char c=getchar();
	while (!isd(c)){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (isd(c)){
		i=i*10+c-'0';
		c=getchar();
	}
	return i*f;
}
namespace task1to10{
	int l[5005],r[5005];
	long long ans=0;
	long long myabs(long long a){
		return ((a>0ll)?a:-a);
	}
	void solve(){
		ans=0;
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		for (int i=1;i<=n;i++){
			l[i]=n;
			for (int j=1;j<=n;j++){
				if (myabs(a[i]-a[j])<=d){
					l[i]=min(l[i],j);
					r[i]=max(r[i],j);
				}
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=i+3;j<=n;j++){
				if (r[i]-l[j]==1) ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
namespace task11to12{
	void solve(){
		long long D=a[2]-a[1];
		if (d<2*D){
			cout<<0<<"\n";
			return;
		}
		cout<<max(0ll,n-2*(d/D)+1)<<"\n";
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	no_ce=read();
	t=read();
	while (t--){
		n=read();
		d=read();
		for (int i=1;i<=n;i++) a[i]=read();
		else if (no_ce<=10) task1to10::solve();
		else if (no_ce<=12) task11to12::solve();
	}
	cout<<endl;
	return 0;
}
