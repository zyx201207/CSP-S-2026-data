#include <bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q,z[500010],x[500010][10],l[100010][2],v[500010][2],zx,g=0;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c >>n >>m >>d >>q;
	for(int i=1;i<=m;i++) cin >>z[i];
	for(int i=1;i<=n;i++){
		cin >>x[i][1];
		for(int j=1;j<=x[i][1]*2;j++){
			cin >>x[i][j+1];
			if(j%2!=0){
				if(v[x[i][j]][1]!=0) zx=min(zx,v[x[i][j]][1]+x[i][j+1]);
				v[x[i][j]][1]+=x[i][j+1];
			}
		}
	}
	for(int i=1;i<=q;i++) cin >>l[i][1] >>l[i][2];
	for(int i=1;i<=q;i++){
		int ans=INT_MAX,b1=INT_MAX,b2=INT_MAX;
		g=0;
		for(int j=1;j<=n;j++){
			int a1=0,a2=0;
			for(int k=2;k+=2;k<=x[j][1]){
				if(x[j][k]==l[i][1]) a1=x[j][k+1];
				if(x[j][k]==l[i][2]) a2=x[j][k+1];
				if(a1!=0&&a2!=0) ans=min(a1+a2,ans),g=1;
				b1=min(a1,b1);b2=min(a2,b2);
			}
		}
		if(g==1) cout <<z[l[i][1]]+z[l[i][2]]+ans <<endl;
		else cout <<z[l[i][1]]+z[l[i][2]]+b1+b2+zx <<endl;
	}
	return 0;
}
