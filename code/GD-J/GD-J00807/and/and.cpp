#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
long long s[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	if (m==3){
		long long ans=-1e9;
		for (int i=1;i<=n;i++) cin >> a[i];
		for (int i=1;i<=n-2;i++){
			for (int j=i+1;j<=n-1;j++){
				for (int k=i+2;k<=n;k++){
					long long sum=a[i]&a[j]&a[k];
					ans=max(ans,sum);
				}
			}
		}
		cout << ans;
		return 0;
	}
	if (1==1){
		if (m==1){
			long long ans=-1e9;
			for (int i=1;i<=n;i++){
				long long x;
				cin >> x;
				ans=max(ans,x);
			}
			cout << ans;
			return 0;
		}else if (n==m){
			long long sum=0;
			for (int i=1;i<=n;i++){
				long long x;
				cin >> x;
				sum&=x;
			}
			cout << sum;
			return 0;
		}else if (m==2){
			for (int i=1;i<=n;i++) cin >> a[i];
			long long sum=-1e9;
			for (int i=1;i<=n-1;i++){
				for (int j=i+1;j<=n;j++){
					sum=max(sum,a[i]&a[j]);
				}
			}
			cout << sum;
			return 0;
		}else if (m==n-1){
			cout << 0;
			return 0;
		}else{
			int ok=1;
			if (m==2) ok=0;
			for (int i=1;i<=n;i++){
				cin >> a[i];
				if (a[i]>=4) ok=0;
			}
			sort(a+1,a+n+1,cmp);
			if (ok==1){
				s[1]=a[1];
				for (int i=2;i<=m;i++){
					s[i]=s[i-1]&a[i];
				}
				cout << s[m];
			}else{
				long long sum=0;
				s[1]=a[1];
				for (int i=2;i<=m;i++){
					s[i]=s[i-1]&a[i];
				}
				cout << s[m];
				return 0;
			}
		}
	}
}
