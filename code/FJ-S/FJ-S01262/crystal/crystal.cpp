#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],p[500005],ans=0,k=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		p[i]=a[i]-a[i-1];
	}
	for(long long i=2,u=0,j=1;i<=n;){
		if(ans<=m){
			u++;
			k=max(k,u);
			j++;
			ans+=p[j]*u;
		}else{
			if(j==n)break;
			ans-=a[j]-a[i-1];
			i++;
			u--;
		}
	}
	cout<<k;
	return 0;
}
