#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+5;
long long n,m,a[N],sum=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,greater<long long>());
	if(a[n]==0){
		cout<<0;
		return 0;
	}
	sum=a[1];
	for(int i=2;i<=m;i++) sum=(sum&a[i]);
	cout<<sum;
	return 0;
}
