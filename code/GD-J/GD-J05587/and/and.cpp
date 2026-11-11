#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],s,c[200005]={0},cc=0,l;
void p(int x,int y){
	if(x>m){
		cc=0;
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				c[cc++]=a[i];
			}
		}
		l=c[0];
		for(int i=1;i<cc;i++){
			l=(l&c[i]);
		}
		s=max(l,s);
		return;
	}
	for(int i=y;i<=n;i++){
		b[i]=1;
		p(x+1,i+1);
		b[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	p(1,1);
	printf("%d",s);
	return 0;
}
