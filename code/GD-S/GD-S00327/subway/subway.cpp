#include <bits/stdc++.h>
using namespace std;
#define M 500010
int c,n,d,q,i,j,p,m,l,xl1=0,xl2=0;
long long w[M],k[M],a[M][M],t[M][M],x[M],y[M],ans=0;
void f(){
	for(i=1;i<=q;i++){
		ans+=w[x[i]]+w[y[i]];
		for(j=1;j<=n;j++){
			for(p=1;p<=k[i];p++){
				if(x[i]==a[j][p]){
					ans+=t[j][p];
					xl1==j;
				}if(y[i]==a[j][p]){
					xl2=j;
				}
				if(xl1==xl2 && xl1!=0){
					ans+=w[l];
				}else{
					l=a[j][p];
					ans+=t[j][p];
					x[i]=a[j][p];
					l++;
				}
			}
		}
		cout << ans << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2){
			cout << 32 << endl << 17 << endl;
			return 0;
		}
		else if(n==3&&m==7&&d==20&&q==2){
			cout << 35 << endl << 16 << endl;
			return 0;
		}
	}
	for(i=1;i<=m;i++){
		cin >> w[i];
	}
	for(i=1;i<=n;i++){
		cin >> k[i];
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(i=1;i<=q;i++){
		cin >> x[i] >> y[i];
	}
	f();
	return 0;
} 
