#include<bits/stdc++.h>
using namespace std;
int c;
long long n,m,d,q;
long long w[10010];
long long k;
long long a[10010];
long long t[10010];
long long x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	while(q--){
		cin>>k;
		for(int i=1;i<=2*k;i++){
		cin>>a[i];
		cin>>t[i];
	}
	cin>>x>>y;
	}
	cout<<(y-x)*t[1];
	return 0;
} 
