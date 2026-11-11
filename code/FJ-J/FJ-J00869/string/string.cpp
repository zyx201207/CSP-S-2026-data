#include <cstdio>
#include <algorithm>
#include <cmath>
#define N 200005
using namespace std;

struct Node{
	long long num;
	char c;
} a[N], l[N/2+1], r[N/2+1];
int n, cntl, cntr;
long long sum, cntn, ans, halfs;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%lld%1s", &a[i].num, &a[i].c);
		sum+=a[i].num;
	}
	
	halfs=sum/2;
	for(int i=1;i<=n;i++){
		cntn+=a[i].num;
		if(cntn > halfs){
			r[++cntr].num=min(a[i].num, cntn-halfs);
			r[cntr].c=a[i].c;
			int tmpl=a[i].num-cntn+halfs;
			if(tmpl > 0){
				l[++cntl].num=tmpl;
				l[cntl].c=a[i].c;
			}
			continue;
		}
		l[++cntl].num=a[i].num;
		l[cntl].c=a[i].c;
	}
	if(sum%2 == 1) r[1].num-=1;
	
//	for(int i=1;i<=cntl;i++){
//		printf("L: %lld %c\n", l[i].num, l[i].c);
//	}
//	for(int i=1;i<=cntr;i++){
//		printf("R: %lld %c\n", r[i].num, r[i].c);
//	}
	
	int i=cntl, j=1;
	while (i >= 1 && j <= cntr){
		if(l[i].num <= 0) i--;
		if(r[j].num <= 0) j++;
		
		long long x=min(l[i].num, r[j].num);
//		printf("L %lld, R %lld, x %lld\n", l[i].num, r[j].num, x);
		if(l[i].num >= r[j].num){
			l[i].num-=x;
			r[j].num=0;
		}
		else{
			r[j].num-=x;
			l[i].num=0;
		}
		
		if(l[i].c != r[j].c){
			ans+=x;
			x=0;
		}
	}
	
	printf("%lld", ans);
	return 0;
}
