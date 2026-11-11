#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long a[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    long long n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	long long maxncnt=LONG_MIN;
	for(long long i=2; i<=n; i++){
		long long k=m;
		long long cnt=i-1;
		while(k&&cnt>=1){
			if(k>=(a[i]-a[cnt])){
				k-=(a[i]-a[cnt]);
				cnt--; 
			}else{
				cnt++;
				break;
			}
		}
		maxncnt=max(maxncnt,i-cnt);
	} 
	cout<<maxncnt;
	return 0;
}
