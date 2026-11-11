#include <bits\stdc++.h>
using namespace std;

long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//Ì°ÐÄ
	long long n,m;
	cin >> n >> m;
	//scanf("&ll",n);
	//scanf("&ll",m);
	for(long long i=1;i<=n;i++){
		cin >> a[i];
		//scanf("&ll",a[i]);
	}
	sort(a+1,a+n+1);
//	for(long long i=1;i<=n;i++){
//		cout << a[i] << ' ';
//	}
	long long ans=0;
	for(long long j=n;j>=1;j--){
		long long p=m,s=0;
		for(long long i=j;i>=1;i--){
			if(a[j]-a[i]<=p){
				s++;
				p-=(a[j]-a[i]);
			}
			else{
				break;
			}
			ans=max(ans,s);
			if(ans==j){
				break;
			}
		}
	}
	cout << ans;
	//printf("&ll",ans);
	return 0;
}
