#include<bits/stdc++.h>
#define N 500009
using namespace std;long long n,m,i,a[N],ans,s,sum;priority_queue<long long>p;
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);sort(a+1,a+1+n);
	for(i=1;i<=n;i++){
		sum++;while(s>m){
			s+=p.top();p.pop();sum--;
		}if(i<n)s+=sum*(a[i+1]-a[i]);
		p.push(-a[i]);ans=max(ans,sum);
	}printf("%lld",ans);
	return 0;
}//Oct31==Dec25?
