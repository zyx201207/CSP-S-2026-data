#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;

struct node {
	char s;
	ll n;
};
ll sum=0;

node a[N];

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	int n;
	scanf("%d",n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",a[i].n,a[i].s);

	int i=1,j=n;
	node t=a[i],e=a[j];
	
	while(i<=j){
		if(t.n<=0){
			ll x=t.n;
			t=a[++i];
			t.n=t.n+x;
		}
		if(e.n<=0){
			ll x=e.n;
			e=a[--j];
			e.n=e.n+x;
		}
		if(i==j)
			break;	
		if(t.s==e.s){
			if(t.n>e.n){
				t.n-=e.n;
				e.n=0;
			}
			else if(t.n==e.n)
				e.n=t.n=0;
			else{
				e.n-=t.n;
				t.n=0;
			}
			continue;
		}
		else{
			if(t.n>e.n){
				t.n-=e.n;
				sum+=e.n;
				e.n=0;
			}
			else if(t.n==e.n){
				sum+=e.n;
				e.n=t.n=0;
			}
			else{
				e.n-=t.n;
				sum+=t.n;
				t.n=0;
			}
			continue;
		}
	}
	printf("%d",sum);
	 
	
	
	
	return 0;
}