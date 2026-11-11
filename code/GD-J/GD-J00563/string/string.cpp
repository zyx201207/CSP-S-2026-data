#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
long long sum;
int n;
struct st{
	long long x;
	char c;
}a[N];
long long l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld %c",&a[i].x,&a[i].c);
	l=1,r=n;
	while(l<r){
		if(a[l].c!=a[r].c)
			if(a[l].x>a[r].x)sum+=a[r].x,a[l].x-=a[r].x,r--;
			else sum+=a[l].x,a[r].x-=a[l].x,l++;
		else{
			if(a[l].x>a[r].x)a[l].x-=a[r].x,r--;
			else a[r].x-=a[l].x,l++;		
		}
	}
	printf("%lld",sum);
	return 0;
}

