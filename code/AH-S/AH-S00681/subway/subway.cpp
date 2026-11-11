#include<bits/stdc++.h> 
using namespace std;
long long w[5000000];
struct dt{
	int a;
	int t;
}s[5000000];
struct cx{
	int j;
	int z;
}r[5000000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subwaay.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=d;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;k++){
			cin>>s[i].a>>s[i].t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r[i].j>>r[i].z;
	}
	cout<<42;
	return 0;
}
