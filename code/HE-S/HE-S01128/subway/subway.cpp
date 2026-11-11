#include<bits/stdc++.h>
using namespace std;

const int maa=2e5+5e4+5;
long long v[maa],ans=1e18;
int c,n,m,d,q,t[maa],x,y;
struct aa{
	int kk;
	int a[maa];
	long long t[maa];
}k[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","W",stdout);
	cin >>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin >>v[i];
	}
	for (int i=1;i<=n;i++){
		cin >>k[i].kk;
		for (int j=1;j<=2*k[i].kk;j++){
			cin >>k[i].a[j]>>k[i].t[j];
		}
	}
	for (int i=1;i<=q;i++){
		ans=0;
		cin >>x>>y;
		for (int j=1;j<=n;j++){
			for (int l=1;j<=k[i].kk;l++){
				if (k[i].a==x && j){
					ans+=
				}
			}
		}
	}
	
	return 0;
} 
