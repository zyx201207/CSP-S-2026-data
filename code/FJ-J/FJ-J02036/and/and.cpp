#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[200005],mn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],mn=max(mn,a[i]);
	if(m==1){cout<<mn;return 0;}
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(a[i]&a[j]>mn) mn=a[i]&a[j];
	if(m==2){cout<<mn;return 0;}
	for(int i=30;i>=0;i--){
		long long cnt=0;
		for(auto y:a) if(y&(1<<i)) cnt++;
		if(cnt>=m){for(auto y:a) if(!(y&(1<<i))) y=0; ans+=(1<<i);} 
	}
	cout<<ans;
	return 0;
}

