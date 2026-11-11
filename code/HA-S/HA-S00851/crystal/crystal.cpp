#include<bits/stdc++.h> 
using namespace std;
long long a[1000000],b[1000000];
int main(){
	freopen("crystal.in","r",stdin)
	freopen("crystal.out","w",stdout)
	long long m,n,c=1e9,v,ans=1;
	cin >> n >> m;
	for(long long i=1;i<=n;i++)
		cin >> a[i];
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++)
			b[i]+=max(a[i],a[j])-min(a[i],a[j]);
			
		if(b[i]<c){
			c=b[i];
			v=i;
		}
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<v;i++){
		long long ji=a[v]-a[i];
		if(m<ji)
		break;
		m=m-ji;
		ans++;
	}
	
	cout << ans;
	
	return 0;
}
