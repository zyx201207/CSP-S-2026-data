#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],dp[N],ans=INT_MIN,ki; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		int cnt=0;
		for (int j=1;j<=n;j++){
			cnt+=a[i]-a[j];
		}
		if (cnt>=ans&&cnt<=m) {
			ans=cnt;
			ki=i;
		}
	}
	cout<<ki;
	return 0;
} 
//µ÷ÁË10·ÖÖÓ¹öÄ¾ 

