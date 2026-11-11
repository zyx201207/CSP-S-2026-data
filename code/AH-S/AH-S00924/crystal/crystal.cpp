#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	c=a[1]-a[0];
	for(int i=0;i<n && m>0;i++){
		for(int j=0;j<=i;j++){
			m-=c;
		}
		ans++;
	}
	cout<<ans;
	return 0;
}
