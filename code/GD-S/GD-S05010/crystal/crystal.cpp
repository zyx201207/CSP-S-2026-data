#include<bits/stdc++.h>
using namespace std;
long long a[500005] ,n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		long long b=m,cnt=0;
		for(long long j=i-1;j>=1;j--){
			if(abs(a[j]-a[i])<=b){
				b-=abs(a[j]-a[i]);
				cnt++;
			}
		}
		cout<<cnt;
	}
} 
