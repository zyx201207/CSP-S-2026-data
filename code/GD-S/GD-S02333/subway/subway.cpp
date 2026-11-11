#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[100005];
long long a[100005],x[100005],y[100005],k[10],t[100005];
long long ans,xb,xbi;
int iny(long long flag){
	for(long long b=1;b<=n;b++){
		flag=0;
		for(long long ii=1;ii<=k[b];ii++){
			if(a[ii]==x[xbi]||a[ii]==y[xbi]){
				flag++;
			}
		}
		if(flag==2){
			xb=b;
			return 1;
		}
	}return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)cin>>w[i];
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>a[i]>>t[i];
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(long long i=1;i<=q;i++){
		ans=0;
		xbi=i;
		long long ffllaagg=iny(0);
		if(ffllaagg==1){
			for(int j=1;j<=k[xb];j++){
				ans+=t[j];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
