#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
long long c,t;
int main() {
	cin>>c>>t;
	while(t--) {
		long long n,m;
		cin>>n>>m;
		map<long long>mp;
		vector<long long> a(n+10,0),cha(n+10,0);
		vector<unsigned long long > pre(n+10,0);
		vector<long long > pre1(n+10,0);
		vector<long long> g[n+10];
		for(int i=0; i<n; i++) {
			cin>>a[i];
			if(i!=0)cha[i]=a[i]-a[i-1];
			pre[i]=pre[i-1]+cha[i];
			pre[i]=pre[i-1]+1;
		}
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				g[i].push_back((pre[j]-pre[i]+m-1)/m);
			}
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				
			}
		}
	}
	return 0;
}

