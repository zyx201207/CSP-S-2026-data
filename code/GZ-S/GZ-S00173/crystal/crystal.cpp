//GZ-S00173 贵阳市新世界学校 李铭赫 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
unsigned long long sum[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m; cin>>n>>m;
	sum[1]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
	}
	while(n--){
		if(m>=sum[n]){
			cout<<n;
			return 0;
		}
		if(n==-1) return 0; 
	}
	return 0;
}
