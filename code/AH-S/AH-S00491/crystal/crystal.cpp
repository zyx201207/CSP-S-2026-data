#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans=0,start=1,need=0;
long long m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		need+=(i-start)*(a[i]-a[i-1]);
		while(need>m){
			smart++;
		}
		ans=max(ans,smart);
	}
	cout<<ans;
	return 0;
}
