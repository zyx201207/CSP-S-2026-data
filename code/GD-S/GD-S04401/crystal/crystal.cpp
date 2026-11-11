#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long cnt=1,t=m;
		for(int j=i-1;j>=1&&t>0;j--) {
			long long k=a[i]-a[j];
			t-=k; 
			if(t<0) break;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
