#include<bits/stdc++.h>

using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}long long ans=1;
	for(int i=1;i<=n;i++){
		long long cnt=1;
		long long t=m;
		if(n-i+1<=ans)break;
		for(int j=1;j<i;j++){
			if(t>=a[i]-a[j]){
				t-=a[i]-a[j];
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
