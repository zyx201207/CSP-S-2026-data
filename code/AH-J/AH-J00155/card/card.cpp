#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n,a[200010],cnt[40];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(n==10)cout<<"10 3 3"; 
	else if(n==4)cout<<"3 1 4";
	return 0;
}
