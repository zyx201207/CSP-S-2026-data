#include<bits/stdc++.h>
using namespace std;
const int M=100000005;
struct d{
	long long s,w;
}a[M];
long long sum;
bool cmp(d x,d y){
	if(x.w!=y.w) return x.w>y.w;
	else return x.s>y.s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i].s;
		int b=a[i].s;
		while(b>0){
			if(b%2==1){
				a[i].w++;
			}
			b=b/2;
		}
	}
	sort(a+1,a+n+1,cmp);
	while(m>1){
		sum=a[1].s&a[2].s;
		a[2].s=sum;
		a[1].s=0,a[1].w=0;
		m--;
		sort(a+1,a+n+1,cmp);
	}
	cout << sum;
	return 0;
}
