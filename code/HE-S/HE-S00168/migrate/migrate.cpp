#include<bits/stdc++.h>
using namespace std;
#define int long long
const size_t mn1 = (size_t)(5100);
const size_t mn = (size_t)(5e5+100);
int C,T,n,m,a[mn],b[mn],ans=0;
int d[mn1][mn1],c[mn1][mn1];
void f10() {
	memset(d,0x3f,sizeof(d));
	memset(c,0,sizeof(c));
	ans=0;
	for(int i=0; i<n; i++) {
		for(int j=i+1,t=a[i+1]-a[i]; j<n && t<=m; j++,t=a[j]-a[i]) {
//			cout<<i<<" "<<j<<endl;
			d[i][j]=1;
			d[j][i]=1;
			c[i][j]++;
			c[j][i]++;
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			for(int k=i+1; k<=j-1; k++) {
				if(d[i][j]>d[i][k]+d[k][j]) {
					d[i][j]=d[i][k]+d[k][j];
					c[i][j]=1;
				} else if(d[i][j]==d[i][k]+d[k][j]) {
					c[i][j]++;
				}
			}
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(c[i][j]==2) ans++;
//			cout<<c[i][j]<<" ";
		}
//		cout<<endl;
	}
	printf("%lld\n",ans);
}
void fA() {
//	cout<<"A"<<endl;
	int ch=a[1]-a[0];
	int h=(m+ch-1)/ch;
	ans=max(n-(h*2)+1,0LL);
	cout<<ans<<endl;
}
void fB() {
	cout<<0<<endl;
}
void fC() {
	f10();
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--) {
		cin>>n>>m;
		for(int i=0; i<n; i++) {
			scanf("%lld",&a[i]);
		}
//		if(C<=10) f10();
		if(C<=12) fA();
		else if(C<=14) fB();
		else if(C<=18) fC();
		else f10();
	}
	return 0;
}
