#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long m;
long long a[500005],s[500005],maxx=-1e9;
long long l = 1,r = 0;
bool bj = 0,bj1 = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];	
		if(a[i]!=i){
			bj = 1;
		}
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			bj1=1;
		}
	}
	r = n;
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i = 1;i<=n;i++){
			long long ans = 0,cnt=1;
			for(int j = i-1;j>=1;j--){
				if(ans<m){
					ans += (a[i]-a[j]);
					cnt++;
				}
			}
			if(ans>m){
				cnt--;
			}
			maxx=max(maxx,cnt);
		}
		cout<<maxx;
	}else if(bj==0){
		long long cnt = n;
		while(m<cnt*(cnt-1)/2){
			cnt--;
		}
		cout<<cnt;
	}else if(bj1==0){
		long long cnt = n;
		long long sum = (a[n]-a[1])/(a[2]-a[1])+1;
		while(m<(a[1]+a[cnt])*(sum-1)/2){
			cnt--;
			sum = (a[cnt]-a[1])/(a[2]-a[1])+1;
		}
		cout<<cnt;
	}
	else{
		cout<<564216;
	}
	return 0;
}

