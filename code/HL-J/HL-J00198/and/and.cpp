#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
unsigned long long n,m;
unsigned long long a[N];
unsigned long long b[N];
unsigned long long maxn,maxm,maxz,ans;
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(unsigned long long i=1;i<=n;i++){
    	cin>>a[i];
    	maxn=max(maxn,a[i]);
	}

	if(m==1){
		cout<<maxn;
	}
	if(m==2){
		for(unsigned long long i=1;i<=n;i++){
			for(unsigned long long j=i+1;j<=n;j++){
				maxm=max(maxm,a[i]&a[j]);
			}
		}
		cout<<maxm;
	}
	else{
		sort(a+1,a+n+1);
		reverse(a+1,a+1+n);
		for(unsigned long long i=1;i<m;i++){
			maxz=max(maxz,ans&(a[i]&a[i+1]));
			ans=a[i]&a[i+1];
		}
		cout<<maxz;
	}
    return 0;
}
