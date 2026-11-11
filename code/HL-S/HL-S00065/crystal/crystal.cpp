#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],sum[500005],q[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		sum[i]=a[i]-a[i-1];
	}
	for(long long i=1;i<=n;i++){
		q[i]=sum[i+1]*i;
	}
	long long s;
	for(s=2;s<=n;s++){
		if(q[s]<=m){
			m-=q[s];
		}else{
			break;
		}
	}
	cout<<s<<endl;
	return 0;
}
