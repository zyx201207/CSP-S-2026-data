#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],cha[500010],sum[500010],num[500010],ans[500010],cnt,cnt1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 2;i <= n;i++){
		cha[i]=a[i]-a[i-1];
		num[i]=num[i-1]+cha[i]*(i-1);
	}
	int pos=1;
	for(int i = 1;i <= n;i++){
		num[i]=num[i-1]+cha[i]*(i-pos);
		if(m>=num[i]){
			ans[i]=ans[i-1]+1;
		}
		else{
			ans[i]=ans[i-1]+1;
			while(m<num[i]){
				num[i]-=(a[i]-a[pos]);
				pos++;
				ans[i]--;
			}
//			if(cnt1<=i-pos+1) cnt1=i-pos+2;
//			cnt1=max(i-pos+1,cnt1);
		}
		cnt=max(ans[i],cnt);
	}
	cout << cnt;
	return 0;
}

