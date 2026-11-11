#include <bits/stdc++.h>
using namespace std;
const long long N=2e5+50;
long long a[N],v[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
		v[i]=1;
	}
	long long ans=0;
	for(long long i=31;i>=0;i--){
		int cnt=0;
		for(long long j=1;j<=n;j++){
			if(!v[j]) continue;
			if((a[j]>>i)&1){
				cnt++;
			}else{
				v[j]=2;
			}
		}
		if(cnt<m){
			for(long long j=1;j<=n;j++){
				if(v[j]==2) v[j]=1;
			}
		}else{
			for(long long j=1;j<=n;j++){
				if(v[j]==2) v[j]=0;
			}
			ans+=(1<<i); 
		}
	}
	cout << ans << endl;
}
