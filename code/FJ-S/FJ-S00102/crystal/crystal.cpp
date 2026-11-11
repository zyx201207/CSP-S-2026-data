#include <bits/stdc++.h>
using namespace std;
int n;
long long mz;
long long a[500005];
int ans;
void tf(){
	long long s=a[2]-a[1];
	long long d=s;
	long long m=mz;
	while (m>=0){
		if (m>=d){
			m-=d;
			ans++;
		}else {
			ans++;
			break;
		}
		d+=s;
	}
	if (ans>=n){
		cout<<n;
	}else{
		cout<<ans;
	}
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>mz;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if (mz>1e18){
		tf();
		return 0;
	}
	for (int i=1;i<=n;i++){
		if (a[i]==a[i+1])continue;
		int cnt=0;
		long long m=mz;
		int x=a[i];
		for (int j=i;j>=1&&m>=0;j--){
			if (a[j]==x){
				cnt++;
				continue;
			}
			else if (m-x+a[j]>=0) {
				m=m-x+a[j];
				cnt++;
			}
			else break;
		}
		if (ans==0)ans=cnt;
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}

