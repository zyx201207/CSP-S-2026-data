#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+37;
const int M=370+370;
int _x[N];
struct jkl {
	int t,p;
	bool operator<(const jkl &T)const {
		return t>T.t;
	}
} x[N][37];
vector<jkl>v[M];
int y[M];
int _y[M];
vector<int>_v[M];
int fa[M],de[M],hs[M],si[M];
int top[M];
void d1(int p,int f) {
	fa[p]=f;
	de[p]=de[f]+1;
	si[p]=1;
	for(int i:_v[p]) {
		if(i==f) {
			continue;
		} else {
			d1(i,p);
			si[p]+=si[i];
			if(si[i]>si[hs[p]]) {
				hs[p]=i;
			}
		}
	}
}
void d2(int p,int t) {
	top[p]=t;
	if(!hs[p]) {
		return;
	} else {
		d2(hs[p],t);
		for(int i:_v[p]) {
			if(i==hs[p]|i==fa[p]) {
				continue;
			} else {
				d2(i,i);
			}
		}
	}
}
int LCA(int a,int b) {
	int _a=a,_b=b;
	while(top[a]!=top[b]) {
		if(de[top[a]]>de[top[b]]) {
			swap(a,b);
		}
		b=fa[top[b]];
	}
	if(de[a]>de[b]) {
		swap(a,b);
	}
	return y[_a]-y[a]+y[_b]-y[a];
}
signed main() {
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a,b,c,d;
	cin>>a>>a>>b>>c>>d;
	for(int i=1; i<=b; i++) {
		cin>>_x[i];
	}
	for(int i=1; i<=a; i++) {
		y[i]=4e18+37;
		int k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			int t,p;
			cin>>t>>p;
			v[i].push_back({t,p});
			x[t][++x[t][0].t]= {i,p};
		}
	}
	priority_queue<jkl>q;
	q.push({0,1});
	y[1]=0;
	_y[1]=0;
	while(!q.empty()) {
		jkl p=q.top();
		q.pop();
		if(y[p.p]<p.t) {
			continue;
		} else {
			for(jkl i:v[p.p]) {
				for(int j=1; j<=x[i.t][0].t; j++) {
					if(x[i.t][j].t==p.p) {
						continue;
					} else {
						int np=p.t+i.p+x[i.t][j].p;
//						cout<<np;
						if(np<y[x[i.t][j].t]) {
							y[x[i.t][j].t]=np;
							_y[x[i.t][j].t]=p.p;
//							cout<<p.p<<' '<<i.t;
							q.push({np,x[i.t][j].t});
//							cout<<p.t<<' '<<i.p<<' '<<x[i.t][j].p<<'\n';
//							cout<<np;
						}
					}
				}
			}
		}
	}
	for(int i=1; i<=a; i++) {
		_v[i].push_back(_y[i]);
		_v[_y[i]].push_back(i);
	}
	d1(1,0);
	d2(1,1);
	for(int i=1; i<=d; i++) {
		int f,t;
		cin>>f>>t;
		long long ans=4e18+37;
		for(int i=1; i<=x[f][0].t; i++) {
			for(int j=1; j<=x[t][0].t; j++) {
				ans=min(ans,LCA(x[t][j].t,x[f][i].t)+x[t][j].p+x[f][i].p);
			}
		}
		cout<<ans+_x[f]+_x[t]<<'\n';
	}
//	for(int i=1; i<=a; i++) {
//		cout<<y[i];
//	}
	return 0;
}
