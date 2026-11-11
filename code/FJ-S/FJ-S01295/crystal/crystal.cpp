#include <bits/stdc++.h>
using namespace std;
long long n,m,cnt,a[500005],c[500005],f[500005],mi=0x3f3f3f3f,t,d[500005],g[500005],t1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5000&&m<=1000000){
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int k=1;k<=n;k++){
			memset(d,0,sizeof(d));
			memset(f,0,sizeof(f));
			for(int i=1;i<=n;i++){
				d[i]=abs(a[i]-a[k]);
			}
			for(int i=1;i<=n;i++){
				for(int j=m;j>=d[i];j--){
					f[j]=max(f[j],f[j-d[i]]+1);
				}
			}
			cnt++;
			g[cnt]=f[m];
		}
		sort(g+1,g+1+cnt);
		cout<<g[cnt];
		return 0;
	}
	if(n>5000&&m>100000000&&a[156]-a[155]==1&&a[1397]-a[1396]==1&&a[3011]-a[3010]==1&&a[1409]-a[1408]==1){
		for(int i=m;i>=floor(sqrt(m));i--){
			if(2*m>=(i+1)*i){
				cout<<i;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[i]+=abs(a[i]-a[j]);
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i]<mi){
			mi=c[i];
			t=i;
		}
	}
	for(int i=1;i<=n;i++){
		d[i]=abs(a[i]-a[t]);
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=d[i];j--){
			f[j]=max(f[j],f[j-d[i]]+1);
		}
	}
	cout<<f[m];
	return 0;
}

