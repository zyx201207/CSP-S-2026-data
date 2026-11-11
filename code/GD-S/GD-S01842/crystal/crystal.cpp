#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500005;
ll n,m,t,mx,sm,sn,pn,pm;

struct node{
	ll id,v;
}b[N],a[N];

bool cmp(node x,node y){
	return x.v<y.v;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].v);
	}
	sort(a+1,a+n+1,cmp);
	ll cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i].v!=a[i-1].v) cnt++;
		a[i].id=cnt;
		b[cnt].v++;
		b[cnt].id=a[i].v;
	}
	
	pn=b[1].v;
	mx=pn;
	pm=0;
	t=1;
//	cout<<pm<<' '<<pn<<'\n';
	for(int i=2;i<=cnt;i++){
		sm=pn*(b[i].id-b[i-1].id)+pm;
		sn=b[i].v+pn;
//		cout<<"\n"<<"pre:"<<sm<<' '<<sn<<' '<<b[i].id<<' '<<t<<' '<<b[t].v<<'\n';
		while(sm>m){
			while(b[t].v>0){
				sm-=(b[i].id-b[t].id);
				sn--;
				b[t].v--;
				if(sm<=m) break;
			}
			if(sm<=m) break;
			t++;
		}
		if(b[t].v<=0) t++;
//		cout<<sm<<' '<<sn<<' '<<b[i].id<<' '<<t<<' '<<b[t].v<<'\n';
		pn=sn;
		pm=sm;
		mx=max(mx,sn);
	}
	cout<<mx;
	
	
}

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
