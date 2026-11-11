#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long a[N],key[N],val[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,res=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		long long num=m,asd=0;
		for(long long j=1;j<=i-1;j++){
			long long sum=a[i]-a[i-j];
			if(num-sum>=0){
				num-=sum;
				asd++;
			}
		}
		res=max(res,asd);
	}
	cout<<res+1;
	return 0;
}
