#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
const long long N=50100;
long long a[N];
long long t[N];
long long z[N];
long long sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		z[a[i]]++;	
	}
	if(n>=50000){
		long long f=a[2]-a[1];
		f=m/f;
		long long j=1;
		while(f>=j){
			f-=j;
			j++;
		}
		cout<<j;
		return 0;
	}
	if(m==0){
		long long maxn=INT_MIN;
		for(int i=1;i<=N;i++){
			maxn=max(maxn,z[i]);
		}
		cout<<maxn;
		return 0;
	}
	
	long long s=0;
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		t[i]=a[i]*i-sum;
		if(t[i]<=m){
			s=i;
			break;
		}
	}
	cout<<s;
	return 0;
}

