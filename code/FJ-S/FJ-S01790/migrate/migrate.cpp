#include<iostream>
using namespace std;
long long c,t,n,d,x[2000005],r[2000005],sum;
struct ss{
	long long m,w;
};
ss s(long long a,long long b){
	if(r[a]>=b) return {1ll,1ll};
	long long m=(1ll<<60),w=0ll;
	ss te;
	for(int i=a+1;i<=r[a];i++){
		te=s(i,b);
		if(te.m+1<m) m=te.m+1,w=te.w;
		else w+=te.w;
	}
	return {m,w};
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==11||c==12){
			long long a=d/(x[2]-x[1]);
			if(a<2) cout<<0<<endl;
			else if(a+a-1<n) cout<<n-a-a+1<<endl;
			else cout<<0<<endl;
			continue;
		}
		for(int i=1,j;i<=n;i++){
			for(j=i;j<=n+1;j++) if(x[j]-x[i]>d) break;
			r[i]=j-1;
		}
		for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) if(s(i,j).w==2ll) sum++;
		cout<<sum<<endl;
	}
	return 0;
}
