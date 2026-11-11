#include <bits/stdc++.h>
using namespace std;
long long n,m,a[5*114514];
int ans=-1145141919;
bool A=1,B=1;
int main(){
	 freopen("crystal1.in","r",stdin);
	 freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<n-1;i++){
		if(a[i]!=i)A=0;
		if(a[i]-a[i+1]!=a[i+1]-a[i+2])B=0;
	}
	sort(a+1,a+n+1);
	if(A||B){
		int cnt=1,j=n-1;
		long long x=m;
		while(x>0&&j>=1){
			x-=a[n]-a[j];
			cnt++;
			j--;
		}
		if(x<0)cnt--;
		cout << cnt;
		return 0;
	}
	for(int i=n;i>=1;i--){
		if(i<=ans)break;
		int cnt=1,j=i-1;
		long long x=m;
		while(x>0&&j>=1){
			x-=a[i]-a[j];
			cnt++;
			j--;
		}
		if(x<0)cnt--;
		ans=max(ans,cnt);
	}
	cout << ans;
	return 0;
}
