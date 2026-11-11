#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt=1,ans=0,b=0,c=2;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==i){
			b++;
		}
	}
	if(b==n){
		for(int i=0;i<n;i++){
			if(m*2<i*(i+1)){
				cout<<i;
				return 0;
			} 
		}
	}
	long long d=a[1]-a[0];
	for(c=2;c<n;c++){
		if(d!=a[c]-a[c-1]){
			break;
		}
	}
	if(c==n-1){
		for(int i=0;i<n;i++){
			if(m*2<d*i*(i+1)){
				cout<<i;
				return 0;
			} 
		}
	}
	sort(a,a+n);
	for(long long i=1;i<n;i++){
		long long j;
		for(j=i-cnt;j>=0;j--){
			ans+=a[i]-a[j];
			if(ans>m){
				j++;
				break;
			}
		}
		cnt=max(cnt,i-j);
		ans=ans-a[i]+a[i-cnt+1]+(a[i+1]-a[i])*i;
	}
	cout<<cnt;
	return 0;
}
