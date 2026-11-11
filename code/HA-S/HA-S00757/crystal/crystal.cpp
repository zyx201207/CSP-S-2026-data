#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[500005];
long long sum=1;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	if(n<=16){
		sort(a+1,a+n+1);
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				long long mub=a[j],l=m;
				for(long long k=i;k<j&&l>=0;k++){
					l=l-(mub-a[k]);
				}
				if(l>=0){
					sum=max(sum,j-i+1);
				}
			}
		}
		cout<<sum;
	}
	else{
		sort(a+1,a+n+1);
		a[0]=a[1];
		for(long long i=1;i<=n;i++){
			if(m<(a[1]+a[i])*i/2&&a[i]!=a[i-1]){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
	}
	return 0;
}
//来自中原一群伙伴，结庐东南山， 
