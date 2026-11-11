#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long c;
	bool flag=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2){
			c=a[i]-a[i-1];
		}else if(i>=3&&a[i]-a[i-1]!=c){
			flag=0;
		}
	}
	if(flag){
		ans=1;
		long long num=c;
		while(m>=num){
			m-=num;
			ans++;
			num+=c;
		}
		cout<<min(ans,n);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int cnt=0;
		long long num=0;
		for(int j=i;j>=1;j--){
			if(num+a[i]-a[j]>m) break;
			num+=a[i]-a[j];
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
