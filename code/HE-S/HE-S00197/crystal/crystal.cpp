#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		long long x=m;
		long long cnt=1;
		for(int j=i+1;j<=n;j++){
			x-=a[i]-a[j];
			if(x<0) break;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
