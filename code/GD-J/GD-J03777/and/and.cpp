#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,a[MAXN],b[MAXN][35],c[35],m;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int l=a[i],ip=0;
		while(l){
			b[i][ip]=l&1;
			c[ip]+=l&1;
			l>>=1;
			ip++;
		}
		
	}
	int le=0;
	for(int i=30;i>=0;i--){
		if(c[i]>=m){
			int o=m,ip=1;
			while(o){
				while(!b[ip][i])ip++;
				if(o==m)le=a[ip];
				le&=a[ip];
				ip++;
				o--;
			}
			break;
		}
	}
	printf("%d",le);
	return 0;
}
