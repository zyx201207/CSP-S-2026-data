#include<bits/stdc++.h>
using namespace std;
const int M=2e5+15;
struct str{
	long long h,l,dis;
	char u;
	}y[M];
	int n;
long long m,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		long long d;
		cin>>d>>y[i].u;
		y[i].h=y[i-1].l+1;
		y[i].l=y[i].h+d-1;
		y[i].dis=d;
//cout<<y[i].h<<" "<<y[i].l<<" "<<y[i].dis<<" "<<y[i].u<<endl;
		m+=d;
		}
	long long a=1,b=n
	;
	for(long long i=1,j=m;abs(i-j)>1&&a!=b;){
		long long d=min(y[a].dis,y[b].dis);
		if(y[a].u!=y[b].u)cnt+=d;
		i+=d;j-=d;
		y[a].dis-=d;
		y[b].dis-=d;
		if(i==y[a+1].h)a++;
		if(j==y[b-1].l)b--;
//printf("%lld %lld\n",a,b);
		}
	printf("%lld",cnt);
	return 0;
}
