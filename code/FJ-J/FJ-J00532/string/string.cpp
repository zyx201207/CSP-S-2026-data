#include<bits/stdc++.h>
using namespace std;
struct s{
	long long d;
	char q;
}a[200005];
long long sum=0,n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	long long d;
	for(long long i=1;i<=n;i++)
		cin>>a[i].d>>a[i].q;
	long long rr=1,ll=n;
	while(rr<ll){
		long long qm=min(a[rr].d,a[ll].d);
		if(a[rr].q!=a[ll].q){
			sum+=qm;
		}
		if(a[rr].d>a[ll].d){
			ll--;
			a[rr].d-=qm;
		}else{
			rr++;
			a[ll].d-=qm;
		}
	}
	cout<<sum;
	return 0;
}
