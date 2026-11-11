#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
long long n,m,a[N],cha[N],ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=2;i<=n;i++){
			cha[i] = a[i]-a[i-1];
		}
		long long sum,cnt;
		for(int i=1;i<=n;i++){
			sum=0,cnt=0;
			int j=i;
			while(j<n){
				if(sum+cha[j+1]>m){
					break;
				}
				cnt++;j++;
				sum+=cha[j]*cnt;
			}
			cnt++;
			ans = max(ans,cnt);
		}
		cout << ans;
	}else{
		long long c=a[2]-a[1],cc=0;
		for(int i=1;i<=n;i++){
			if(cc+i*c>m){
				break;
			}else{
				cc+=i*c;
				ans++;
			}
		}
		ans++;
		cout << ans;
	}
	return 0;
}
