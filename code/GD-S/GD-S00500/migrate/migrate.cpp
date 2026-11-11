#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6;
ll c,t,n,d,x[N+10],v[N+10][2],g[N+10][2],s,tn;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--) {
		++tn;
		s=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) 
			cin>>x[i];
		for(int i=1,j=3;i<=n&&j<=n;i++) {
			while((abs(x[j]-x[i])<=d||i+2>=j)&&j<=n) j++;
			if(j>n) break;
			if(abs(x[j-1]-x[i])<=d&&abs(x[j]-x[i+1])<=d&&(j-i+1)==4) v[i][0]=j,v[j][1]=i;
		}
		ll lt=1;
		for(int i=1;i<=n;i++) {
			if(v[i][0]) {
				g[i][0]=i-lt+1;
				lt=i+1;
			}
			if(abs(x[i+1]-x[i])>d) lt=i+1;
		}
		ll rt=n;
		for(int i=n;i>=1;i--) {
			if(v[i][1]) {
				g[i][1]=rt-i+1;
				rt=i-1;
			}
			if(abs(x[i]-x[i-1])>d) rt=i-1;
		}
		for(int i=1;i<=n-3;i++) 
			if(v[i][0]) s+=g[i][0]*g[v[i][0]][1];
		for(int i=1;i<=n;i++)
			v[i][0]=v[i][1]=g[i][0]=g[i][1]=0;
		cout<<s<<"\n";
	}
	
	
	
	return 0;
} 
