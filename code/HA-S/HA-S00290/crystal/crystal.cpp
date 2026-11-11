#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long ans = 0;
long long a[500007];
bool isa = true;
bool isb = true;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i] != i)isa = false;
		if(i > 2 && a[i]-a[i-1] != a[i-1] - a[i-2])isb = false;
	}
	if(isa){
		long long i = 1;
		while(m > 0){
			if(m - i >= 0){
				ans++;
				m -= i;
				i++;
			}else{
				break;
			}
		}
		cout<<ans+1;
		return 0;
	}
	if(isb){
		long long k = a[2] - a[1];
		long long i = k;
		while(m > 0){
			if(m - i >= 0){
				ans++;
				m -= i;
				i+=k;
			}else{
				break;
			}
		}
		cout<<ans+1;
		return 0;
	}
	sort(a,a+n+1);
	for(long long i=n;i>=1;i--){
		long long num = 1;
		long long t = a[i];
		long long mm = m;
		for(long long j = i-1;j >= 1;j--){
			if(t-a[j] > mm){
				break;
			}
			mm -= (t-a[j]);
			num++;
		}
		if(num > ans)ans = num;
	}
	cout<<ans;
	return 0;
}
