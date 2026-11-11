#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
long long a[500005],d[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;++i){
		cin>>a[i];
		d[i]=abs(a[i]-a[i-1]);
	}
	sort(d+1,d+n+1);
	while(m>0){
		m-=d[cnt+1];
		cnt++;
	}
	cout<<cnt;
	return 0;
} 
