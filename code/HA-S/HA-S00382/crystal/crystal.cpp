#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long shu[500100];
long long sum1[500100];
bool cmp(long long a,long long b){
	return a > b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> shu[i];
		
	}
	sort(shu+1,shu+1+n,cmp);
	for(int i = 2;i <= n;i++){
		sum1[i] = sum1[i-1]+shu[1]-shu[i];
	}
	long long mxa = 0;
	long long l = 0,r = n;
	for(long long i = 1;i <= n;i++){
		l = i;
		r = n;
		while(l <= r){
			long long mid = (l+r)/2;
			long long ans = sum1[mid]-(shu[1]-shu[i])*(mid-i)-sum1[i];
			if(ans > m){
				r = mid-1;
			}else if(ans <= m){
				l = mid+1;
				if(mid-i+1 > mxa){
					mxa = mid-i+1;
				}
			}
		}
	}
	cout << mxa;
	return 0;
}
