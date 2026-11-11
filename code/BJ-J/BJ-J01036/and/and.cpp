#include <bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int a[N],f[N];
int sc;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n,cmp);
	f[0]=a[0];
	sc=a[0];
	for(int i=1;i<m;i++){
		sc&=a[i];
	}
	printf("%d",sc);
	return 0;
}
