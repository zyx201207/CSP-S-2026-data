#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,ans=1;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	bool flag=1;
	for(int i=2;i<n;i++)
		if(abs(a[i]-a[i-1])!=abs(a[i+1]-a[i]))
			flag=0;
	if(flag){
		for(int i=n-1;i>=1;i--){
			if(m>=abs(a[n]-a[i])) m-=abs(a[n]-a[i]),ans++;
			else break;
		}
	}else{
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++){
			int k=m,sum=1;
			for(int j=i-1;j>=1;j--){
				if(k>=a[i]-a[j]) k-=a[i]-a[j],sum++;
				else break;
			}
			ans=max(ans,sum);
		}
	}
	cout << ans;
	return 0;
}
