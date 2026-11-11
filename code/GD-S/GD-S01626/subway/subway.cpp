#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,k;
long long x,y;
long long ans = 0;
long long w[500010],a[200020],t[200020];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i = 1; i<= m; i++){
		cin>>w[i];
	}
	for(int i = 1;i<= n;i++){
		cin>>k;
		for(int j = 0;j <= 2 * k;j++){
			cin>>a[j]>>t[j];
		}
	}
	for(int i = 1;i <= p;i++){
		ans = 0;
		cin>>x>>y;
		ans += w[x];
	}
	cout<<ans;
	return 0;
} 
