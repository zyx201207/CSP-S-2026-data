#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n, m;
long long a[N];
long long b[N];
int an=-N;
int ze(){
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int q, maxx=-1;
	for(int l=1,r=1;r<=n;){
		q=b[l];
		int num=0;
		while(r<=n && b[r]==q){
			r++;
			num++;
		}
		l=r;
		maxx=max(maxx,num); 
	}
	return maxx;
}
void f(int x, int num){
	an=max(an,num);
	if(x>=m){
		return ;
	}
	for(int i=1;i<=n;i++){
		a[i]++;
		x++;        
		f(x,ze());
		x--;
		a[i]--;
	}
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	f(0,ze());
	printf("%d\n",an);
	return 0;
}
