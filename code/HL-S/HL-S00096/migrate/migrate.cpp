#include<bits/stdc++.h>
using namespace std;
const int N=2e6+1,INF=0x3f3f3f3f;
int c,t,n;
long long d,g[N];
struct island{
	int l;
	long long x;
}a[N];
bool cmp(island p,island q){
	return p.x<q.x;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i].x;
			a[i].l=i;
		}sort(a+1,a+n+1,cmp);
		for(int i=2;i<=n;i++){
			g[i]=a[i].x-a[i-1].x;
		}bool flag=true;
		for(int i=2;i<n;i++){
			if(g[i]+g[i+1]<=d){
				flag=false;
			}
		}if(flag){
			cout<<0<<endl;
		}else{
			cout<<n/d<<endl;
		}
	}
	return 0;
}
