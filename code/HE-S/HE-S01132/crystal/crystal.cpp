#include<bits/stdc++.h>
using namespace std;
long long n,ans=1,ans_max=1;
long long m;
const long long INF=500010;
long long a[INF],b[INF];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		b[i]=b[i-1]+a[i]; 
	}
	long long cot=0;
	for(long long i=1;i<n;i++){
		for(long long j=n;j>=i+1;j--){
			if(1+(j-i)<=ans_max){
				break;
			}
			cot=(j-1)*a[j]-i*a[i]-(b[j-1]-b[i]);
			if(cot<=m){
				ans=1+(j-i);
				break;
			}
			
		}
		if(ans>ans_max){
			ans_max=ans;
		}
	}
	cout<<ans_max<<endl;
	return 0;
}
