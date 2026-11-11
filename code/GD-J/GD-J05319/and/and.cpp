#include<bits/stdc++.h>
using namespace std;
long long a[100005];
//long long andand(long long a,long long b){
//	string sa,sb,anss;
//	int ansi;
//	while(a){
//		sa=sa+(a%2+'0');
//		a/=2;
//	}
//	while(b){
//		sb=sb+(b%2+'0');
//		b/=2;
//	}
//	for(int i=sa.size(),j=sb.size();i>=0&&j>=0;i--;j--){
//		if(a[i])
//	}
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long ans=a[1];
	for(int i=2;i<=m;i++){
		ans=(ans&a[i]);
	}
	cout<<ans;
	return 0;
}
//4 2
//3 15 12 12

