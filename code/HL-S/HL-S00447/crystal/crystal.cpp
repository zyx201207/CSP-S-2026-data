#include<bits/stdc++.h>
using namespace std;
const long long maxn = 6e5 + 10;

long long cum[maxn];
long long all[maxn];
long long ans = 0;

bool cmp(long long a,long long b){
	return a < b;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	
	if(n == 1){
		cout <<n;
		return 0;
	}
	
	for(long long i = 0;i < n;i++){
		cin >> all[i];
	}
	
	sort(all,all + n,cmp);
	
	cum[0] = all[0];
	
	for(long long j = 1;j < n;j++){
		cum[j] = cum[j -1] + all[j];
	}
	
	long long l = 0;
	long long r = 1;
	
	while(l == 0&&r < n){
		long long p = cum[r];
		long long num = all[r];
		long long ans1 = r - l + 1LL;
		long long x = ans1*num - p;
		//cout << p <<"&"<< num <<"&"<< ans1 <<"&"<< x << endl;
		if(x > m){
			l++;
			break;
		}
		ans = max(ans,ans1);
		r++;
	}
	
	while(l < n&&r < n){
		//cout << "A";
	   	long long p = cum[r] - cum[l - 1];
		long long num = all[r];
		long long ans1 = r - l + 1LL;
		long long x = ans1*num - p;
		if(x > m){
			l++;
			continue;
		}
		ans = max(ans,ans1);
		r++;
	}
	
	cout << ans;
	
	return 0;

}
