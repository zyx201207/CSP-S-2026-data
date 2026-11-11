#include<bits/stdc++.h>
using namespace std;
int n;
bool spcb=1;
long long ma,m,d;
struct node{
	long long c;
	int w; 
}a[500005];
bool cmp2(node l,node r){
	return l.c<r.c;
}
void wk(int x){
	long long tmp=m,ans=0;
	for(int i=1;i<=n;i++){
		if(a[x].w>=a[i].w) a[i].c=a[x].w-a[i].w;
		else a[i].c=1e18+1;
	}
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++){
		if(tmp>=a[i].c){
			ans++;
			tmp-=a[i].c;
		}
		else break;
	}
	if(ans>ma){
		ma=ans;
		d=x;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].w);
	int x=a[2].w-a[1].w;
	for(int i=3;i<=n;i++) if(a[i].w-a[i-1].w!=x) spcb=0;
	if(spcb){
		long long res=1;
		for(int i=2;i<=n;i++){
			long long sum=(x+x*(i-1))*(i-1)/2;
			if(m>=sum) res=i;
			else break;
		}
		cout<<res;
		return 0;
	}
	for(int i=1;i<=n;i++) wk(i);
	cout<<ma;
	return 0;
}
