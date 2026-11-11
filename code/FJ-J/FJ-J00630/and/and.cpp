#include<bits/stdc++.h>
using namespace std;
int n,m;
long long sum=0;
long long a[200005];
string s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	long long maxn=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		maxn=max(a[i],maxn);
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout << maxn;
		return 0;
	}
	if(m==n){
		sum+=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout << sum;
		return 0;
	}
	if(m==2){
		long long ma=0;
		for(int i=1;i<n;i++){
			ma=max(ma,(a[i]&a[n]));
		}
		cout << ma;
		return 0;
	}
	if(m==n-1){
		long long ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<n;j++){
				if(a[j]==a[i]) continue;
				else sum=sum&a[i];
			}
			ma=max(ma,sum);
		}
		cout << ma;
	}
	return 0;
}
