#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[510000];
long long t[510000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;

	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			t[i]++;
		}
	}
	bool flag=1;
	for(long long i=1;i<n;i++){
		if(abs(a[i]-i)==abs(a[i+1]-i)){
			flag=0;
		}
	}
	if(flag==1){
		for(long long i=1;i<=n;i++){
			if(m==(1+i)*i/2){
				cout<<i+1;
				return 0;
			}
		}
	}
	for(long long i=1;i<=n;i++){
		t[i]=1;	
	}
	sort(a+1,a+n+1);
	
	for(long long i=1;i<=n;i++){
		long long num=0;
		long long ans=t[i];
		for(long long j=1;j<=i;j++){
			ans++;
			if(a[i]>=a[j]){
				num+=a[i]-a[j];
				if(num==m){
					cout<<ans;
					return 0;
					}
				}
			}	
		}
return 0;
}
