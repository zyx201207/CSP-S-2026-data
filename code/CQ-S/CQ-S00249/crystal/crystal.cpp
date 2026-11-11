#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	int f=0; 
	cin >> a[1] >> a[2];
	int k=abs(a[1]-a[2]);
	int sum=a[1]+a[2];
	for(long long i=3;i<=n;i++){
		cin >> a[i];
		if(abs(a[i]-a[i-1])!=k){
			f=1;
		}
		sum+=a[i];
	} 
	if(f==0){
		long long j=a[2]-a[1];
		long long i=j;
		long long cnt=0;
		long long ans=0;
		while(m>0){
			cnt++;
			m-=i;
			i+=j;
			ans++;
			if(m<0){
				cnt--;
			}
			if(ans==n-1){
				break;
			}
		}
		cout << cnt+1;
	}
	else{
		cout << n; 
	}
	return 0;	
}

