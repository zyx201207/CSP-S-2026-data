#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500005];
int check(long long b){
	long long m1=0;
		for(long long j=1;j<=b-1;j++){
			m1+=a[b]-a[j];
			if(m1>m)return 0;
		}
		return 1;
	}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long L=1,R=n;
	long long ans=0;
	while(L<=R){
		long long mid=(L+R)/2;
		if(check(mid)){ans=mid;L=mid+1;}
		else R=mid-1;
	}
	long long yu=0;
	for(long long i=ans+1;i<=n;i++){
		if(a[i]>a[ans])break;
		else yu++;
	}
	cout<<ans+yu;
	return 0;
}
