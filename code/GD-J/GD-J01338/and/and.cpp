#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a[N];
void shai(int ad){
	int i=1,s=0;
	while(i<=n-s){
		if(!(a[i]&ad))swap(a[i],a[n-s]),++s;
		else i++;
	}if(n-s>=m)n-=s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1<<30;i>=1;i>>=1){
		shai(i);
	}
	int z=a[1];
	for(int i=2;i<=m;i++)z&=a[i];
	printf("%d",z);
	return 0;
}
