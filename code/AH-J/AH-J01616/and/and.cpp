#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	long long cc=a[1];
	if(m==n){
		for(int i=2;i<=n;i++){
			cc&=a[i];
		}
		cout<<cc;
		return 0;
	}
	long long ans=0;
	for(int i=n/2,j=n/2+1,cnt=0;cnt<=m/2;i--,j++,cnt++){
		ans=max(ans,(long long)(a[i]&a[j]));
	}
	cout<<ans;
	return 0;
}
