#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt=0,id=1,ans=1;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		cnt+=(i-id)*(a[i]-a[i-1]);
		while(cnt>m){
			cnt-=a[id];
			id++;
		}
		ans=max(ans,i-id+1);
	}
	cout<<ans<<endl;
	return 0;
}
