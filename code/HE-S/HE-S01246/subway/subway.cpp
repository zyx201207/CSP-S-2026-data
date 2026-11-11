#include<bits/stdc++.h>
using namespace std;
const long long N=5*1e5+5;
long long key,val[N];
struct train{
	long long a[N];
	long long time[N];
}train[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		key=i;
		cin>>val[key];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;2*j<=k;j++){
			cin>>train[i].a[j];
			cin>>train[i].time[j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		
	}
	return 0;
}
