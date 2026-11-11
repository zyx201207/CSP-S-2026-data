#include<bits/stdc++.h>
using namespace std;
long  long n,m,ans,sum;
struct U {
	int a,b;
};
U u[500005];
bool cmp(U x,U y) {
	return x.b<y.b;
}
int main() {
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>u[i].a;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			u[j].b=u[i].a-u[j].a;
		}
		sort(u+1,u+n+1,cmp);
		long long l=m;
		sum=0;
		for(int i1=1; i1<=n; i1++) {
			if(l-u[i1].b>=0&&u[i1].b>=0) {
				sum++;
				l-=u[i1].b;
			}
		}
		ans=max(sum,ans);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9


*/
