#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll C,T;
ll n,k;
ll dm[2000001];

struct node {
	ll x,y,h;
};
node a[2000011];
ll h[1000001];
ll b[1000001];
//ll check(ll op){
//	for(int i=1;i<=n;i++){
//		if(b[i]==1){
//			f(i);
//		}
//	}
//}
ll d[1000001];
ll dd,ddd;
void f(ll x,ll fa) {
	d[x]=d[fa]+1;
	if(d[x]>dd) {
		ddd=x;
		dd=d[x];
	}
	for(int i=h[x]; i; i=a[i].h) {
		if(a[i].y!=fa) {
			f(a[i].y,x);
		}
	}
}
ll qweasd[1000001];
ll staack[1000001];
ll st=0;
ll dx[1000001];
ll ddq;
ll dop;
void fx(ll x,ll fa) {
	st++;
	staack[st]=x;
	dx[x]=dx[fa]+1;
	if(x==ddd) {
		return;
	}
	for(int i=h[x]; i; i=a[i].h) {
		if(a[i].y!=fa) {
			fx(a[i].y,x);
		}
	}
	st--;
}
ll dq,dddq;
ll son[1000001];
ll sonmax[1000001];
void ff(ll x,ll fa) {
	son[x]=1;
	d[x]=d[fa]+1;
	ll masd=0;
	for(int i=h[x]; i; i=a[i].h) {
		if(a[i].y!=fa) {
			ff(a[i].y,x);
			if(son[a[i].y]>=masd) {
				sonmax[x]=a[i].y;
				masd=son[a[i].y];
			}
			son[x]=max(son[x],son[a[i].y]+1);

		}
	}
}
ll azzz;

void fhub(ll x,ll fa,ll op) {
	op--;
	if(qweasd[x]==0) {
		qweasd[x]=1;
		azzz++;
	}
	if(op==0) {
		return;
	}
	for(int i=h[x]; i; i=a[i].h) {
		if(a[i].y!=fa) {
			ff(a[i].y,x);
		}
	}
}
ll maxx=0,cmaxx=0;
ll maaxx=0,cmaaxx=0;
ll hubb(ll s,ll op) {
	for(int i=1; i<=n; i++) {
		qweasd[i]=0;
	}
	ll l=maaxx;
	while(son[l]>op) {
		l=sonmax[l];
	}
	//qweasd[l]=1;
	ll r=cmaaxx;
	while(son[r]>op) {
		r=sonmax[r];
	}
	//qweasd[r]=1;
	azzz=0;
	fhub(l,0,op);
	fhub(r,0,op);
	if(azzz>=n) {
		return 1;
	} else {
		return 0;
	}
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","W",stdout);
	cin>>C>>T;
	for(int qwerty=1; qwerty<=T; qwerty++) {
		cin>>n>>k;
		ll x,y;
		for(int i=0; i<=n; i++) {
			d[i]=0;
			h[i]=0;
		}
		for(int i=1; i<=n-1; i++) {
			cin>>x>>y;
			b[x]++;
			b[y]++;
			a[i].x=x;
			a[i].y=y;
			a[i].h=h[x];
			h[x]=i;

			a[i+n].x=y;
			a[i+n].y=x;
			a[i+n].h=h[y];
			h[y]=i+n;
		}
		if(n<=2||n<=k) {
			cout<<0<<endl;
			continue;
		}


		dd=0;
		ddd=0;
		f(1,0);
		dq=ddd;
		dd=0;
		ddd=0;
		for(int i=0; i<=n; i++) {
			d[i]=0;
		}
		f(dq,0);
		fx(dq,0);
		ddq=d[ddd];
		dddq=ddq/2;
		for(int i=1; i<=dddq; i++) {
			st--;
		}
		dop=staack[st];
		for(int i=0; i<=n; i++) {
			d[i]=0;
		}
		ff(dop,0);
		for(int i=h[dop]; i; i=a[i].h) {
			if(son[a[i].y]>=maxx) {
				cmaxx=maxx;
				cmaaxx=maaxx;
				maaxx=a[i].y;
				maxx=son[a[i].y];
			}
		}
		ll l=0,r=n-1;
		ll mid;
		while(l<r) {
			mid=(l+r)>>1;
			if(hubb(dop,mid)) {
				r=mid;
			} else {
				l=mid+1;
			}
		}
		cout<<r<<endl;
	}
	return 0;
}
