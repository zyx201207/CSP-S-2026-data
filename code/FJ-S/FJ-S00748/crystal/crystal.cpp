#include <bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxx=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		long long s=m,s_max=1;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=s){
				s-=a[i]-a[j];
				s_max++;
			}
		}
		maxx=max(maxx,s_max);
	}
	cout << maxx;
	return 0;
}
