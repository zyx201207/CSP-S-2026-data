#include <bits/stdc++.h>
using namespace std;
const int N=1E5+5;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);		
	long long c,t,a[N],cnt=0;
	cin>>c>>t;
	long long n,d;
	while(t--){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	if(a[i]+d>=a[n]){//ÌØÊâĞÔÖÊ 
		cout<<i<<'\n';
		continue;
	}
}
}
	return 0;
}
