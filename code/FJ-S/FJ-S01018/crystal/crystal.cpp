#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b=1,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(m>=b*(a[2]-a[1])){
		ans++;
		m-=b*(a[2]-a[1]);
		b++;
	}
	cout<<min(ans,n);
	return 0;
}
