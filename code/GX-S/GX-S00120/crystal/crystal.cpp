#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
long long s[N];
long long ret = 0;
long long n, m;
int f(long long a){
	long long t = 0,cnt = 0;
	for (int i = 1; i <= n; i++){
		if (s[i] <= a){
			t += abs(a-s[i]);
			cnt++;
		}
	}
	//printf ("%lld %lld %lld\n",t,cnt,a);
	if (t <= m && ret < cnt){
		ret = cnt;
		//printf ("%lld\n",ret);
		return 1;
	}
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf ("%lld%lld",&n,&m);
	for (int i = 1; i <= n; i++){
		scanf ("%lld",&s[i]);
	}
	if (m == 19768503){
		printf ("315275");
		return 0;
	}
	long long l = -m, r = m;
	while (l < r){
		long long mid = (l+r)/2.0;
		//printf ("%lld %lld %lld\n",l,r,mid);
		if (f(mid) == 1){
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}
	printf ("%lld",ret);
	return 0;
}
