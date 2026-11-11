#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005],sum1=1,sum2=1;
priority_queue<long long,vector<long long>,greater<long long>> qp;
bool flag=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m==0){
		cout<<1;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		qp.push(a[i]);
	}
	for(int i=3;i<=n;i++){
		if(a[i-2]-a[i-1]!=a[i-1]-a[i]){
			flag=0;
		}
	}
	if(flag){
		long long l=a[2]-a[1];
		long long sum=0,top=1;
		while(m>=0){
			sum++;
			m-=l*top;
			top++;
		}
		cout<<sum;
		return 0;
	}
	for(long long i=1;i<=m;i++){
		long long a=qp.top();
		qp.pop();
		a++;
		qp.push(a);
	}
	long long k=qp.top();
	for(long long i=1;i<=n;i++){
		d[i]=qp.top();
		qp.pop();
	}
	for(long long i=2;i<=n;i++){
		if(k<d[i]&&k>=a[i]){
			sum1++;
		}
	}
	for(long long i=1;i<=n;i++){
		if(d[i]==d[i+1]){
			sum2++;
		}
	}
	cout<<max(sum1,sum2);
	return 0;
}
