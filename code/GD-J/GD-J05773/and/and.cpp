#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=-1,ad=-1;
struct num{
	int a,s1=0;
	bool b=false;
}x[200010];
bool cmp(num x2,num y2){
	if(x2.s1==y2.s1) return x2.a>y2.a; 
	return x2.s1>y2.s1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i].a);
		int t=x[i].a,p=1;
		while(t){
			p*=2;
			t-=t&(-t);
			x[i].s1++;
		}
	}
	sort(x+1,x+n+1,cmp);
	ad=x[1].a;
	for(int i=1;i<=m;i++){
		ad=ad&x[i].a;
	}
	printf("%d",ad);
	return 0;
}
