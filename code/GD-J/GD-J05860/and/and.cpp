#include<bits/stdc++.h>
using namespace std;
int n,m,b[200010];
long long a[200010],t;
int cmp(int x,int y){
	if(b[y]>b[x]){
		return y>x;
	}
	else{
		return x>y;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=a[n]*2;i*=2){
		b[i]=1;
		b[i-1]=i;
		b[i-2]=i-1;
		b[i-3]=i-1;
		b[i-4]=i-1;
	}
	
	sort(a+1,a+1+n,cmp);
	t=a[1];
	for(int i=1;i<=m;i++){
		t=(t&a[i]);
	}
	printf("%lld",t);

	return 0;
} 
