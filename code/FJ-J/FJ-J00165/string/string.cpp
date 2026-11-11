#include<bits/stdc++.h>
using namespace std;
int n;
long long sum,ans;

struct Node{
	char c;
	long long d;
	long long l,r;
}; 

Node a[200010];

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1 ;i <= n ;i++) {
		scanf("%lld",&a[i].d);
		cin>>a[i].c;
		a[i].l = sum;
		sum += a[i].d;
		a[i].r = sum;
	}
	long long mid = (sum+1)/2;
	int s = 1,e = n;
	while(a[s].r<=mid&&a[e].l>=mid) {
		if(a[s].c == a[e].c) {
			if(a[s].d == a[e].d) {
				s++;
				e--;
			}else if(a[s].d < a[e].d) {
				a[e].d -= a[s].d;
				s++;
			}else{
				a[s].d -= a[e].d;
				e--; 
			}
		}else{
			if(a[s].d == a[e].d) {
				ans+=a[s].d;
				s++;
				e--;
			}else if(a[s].d < a[e].d){
				ans+=a[s].d;
				a[e].d -= a[s].d;
				s++;
			}else{
				a[s].d -= a[e].d;
				ans += a[e].d; 
				e--; 
			}
		}
	}
	if(s>e) {
		printf("%lld",ans);
	}  else if(s == e){
		printf("%lld",ans);
	}else {
		if(a[s].c==a[e].c) {
			printf("%lld",ans);
		}else{
			if(a[s].d==a[e].d ) {
				printf("%lld",ans+a[s].d);
			}else if(a[s].d < a[e].d){
				printf("%lld",ans+a[s].d);
			}else{
				printf("%lld",ans+a[e].d);
			}
		}
	}
	return 0;
} 
