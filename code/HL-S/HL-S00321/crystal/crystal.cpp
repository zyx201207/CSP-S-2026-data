#include<bits/stdc++.h>
using namespace std;
long long m,a[500005];
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		long long need=(i-1)*(a[i]-a[i-1]);
		m-=need;
		//cout<<m<<endl;
		if(m<0){
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
}
