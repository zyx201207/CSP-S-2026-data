#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		deque<long long> dq;
		for(int j=i;j<=n;j++){
			dq.push_back(a[i]);
		}
		for(int j=i;j<=n;j++){
			auto t=dq.front();
			dq.pop_front();
			
			dq.push_back(t);
		}
	}
	return 0;
} 
