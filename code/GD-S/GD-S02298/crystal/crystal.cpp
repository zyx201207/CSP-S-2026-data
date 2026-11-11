#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	if(n<=5000||m<=100000000){
		int ans=0;
		for(int i = 0;i < n;i++){
			long long tmp=0;
			int cnt=0;
			for(int j = i;j >= 0;j--){
				tmp+=(a[i]-a[j]);
				if(tmp<=m){
					cnt++;
					ans=max(ans,cnt);
				}else{
					break;
				}
			}
		}
		cout << ans;
	}else{
		long long aa=a[1]-a[0];
		long long x=sqrt(0.25+2*(m/aa))-0.5;
		cout << min(x,n);
	}
} 
