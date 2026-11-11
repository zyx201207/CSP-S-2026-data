#include <bits/stdc++.h>
using namespace std;
const long long N=1e7;
long long a[N];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1]<<endl;
		return 0;
	}
	if(m==n){
		int awy=a[1];
		for(int i=2;i<=n;i++){
			awy=(awy&a[i]);
		}
		cout<<awy<<endl;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=2;i<=m;i++){
		a[1]=(a[1]&a[i]);
	}
	cout<<a[1]<<endl;
	return 0;
}
