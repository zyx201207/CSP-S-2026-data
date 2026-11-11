#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans=1;
//priority_queue<long long> q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	long long i,j,k=0,l=0;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	b[n]=1;
	j=n;
	for(i=n;i>1;i--){
		b[i-1]=a[i]-a[i-1];
		if(m>=b[i-1]+k){
			m-=b[i-1]+k;
			l++;
			k+=b[i-1];
		}
		else{
			ans=max(ans,l+1);
			while(m<b[i-1]+k&&j>i){
				m+=l*b[j-1];
				k-=b[j-1];
				j--;
				l--;
			}
			if(m>=b[i-1]){
				m-=b[i-1]+k;
			    l++;
			    k+=b[i-1];
			}
		}
		//cout<<m<<" "<<i<<" "<<l<<"\n";
	}
	ans=max(ans,l+1);
	printf("%lld",ans);
	return 0;
} 

