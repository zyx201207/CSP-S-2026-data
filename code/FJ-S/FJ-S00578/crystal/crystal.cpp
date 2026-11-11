#include<bits/stdc++.h>
using namespace std;
long long a[500003],minn=1e10,ans=0,cnt=0,ing=0;
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		cnt=0;
		ing=1;
		for(int j=i-1;j>=0;j--){
			cnt+=a[i]-a[j];
			ing+=1;
			if(cnt+a[i]-a[j]>m) break;
		}
		if(abs(cnt-m)<minn){
			minn=abs(cnt-m);
			ans=ing;
		}
	}
	cout<<ans<<endl;
	return 0;
}
