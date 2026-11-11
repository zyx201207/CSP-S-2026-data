#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=1;
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=n;i>=1;i--){
		int b=0;
		for(long long j=i-1;j>=1;j--){
			b+=a[i]-a[j];
			if(b<=m){
				ans=max(ans,i-j+1);
			}else{
				break;
			}
		}
	}
	cout <<ans;
	return 0;
}
