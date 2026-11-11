#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[500002],sum[500002];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;int m1=m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];sum[i]=a[i]-a[i-1];
	}
	int maxa=0;
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){int x=1;
		for(long long j=i+1;j<=n;j++){
			
			long long an=sum[j]*(j-i);
			if(an<=m1){
				m1-=an;
				x++;
			}
		}maxa=max(maxa,x);
	}cout<<maxa;
	return 0;
}