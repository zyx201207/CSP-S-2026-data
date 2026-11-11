//GZ-S00255,贵阳市白云区第十八中学，杨钟源 
#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long ans = 0;
	for(int i = 1;i < n;i++){
		long long s = 0;
		long long p = 1;
		for(int j = i-1;j >= 0;j--){
			s+=a[i]-a[j];
			if (s<=m){
				p++;
			}else{
				break;
			}
		}
		if (p>ans){
			ans=p;
		}
	}
	cout<<ans;
	return 0;
}
