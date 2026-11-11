#include<bits/stdc++.h>
using namespace std;

long long m;
long long n;
long long a[500001];
long long c,n,m,d,q;
long long t[500001];
long long w[500001];


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;m++){
		cin>>a[i]>>w[i];
	}
	
	return 0;
} 
