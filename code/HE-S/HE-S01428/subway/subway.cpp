#include <bits/stdc++.h>
using namespace std;
#define TK1 template <class T1>
using ll = long long;
TK1 using vec = vector<T1>;
TK1 using lr = const T1&;

struct idt{
	ll id,t;
};
struct IDT_MINCMP{
	bool operator()(lr<idt> a,lr<idt> b){ return (a.t < b.t); }
};

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	#define text "subway"
	freopen(text".in","r",stdin); freopen(text".out","w",stdout);
	ll c,n,m,d,q,l,foa=-1,aa,bb; cin >> c >> n >> m >> d >> q; vec<vec<idt>> a;
	cout << m << '\n';
	vec<ll> abmap(m); vec<ll> acmap(n); vec<ll> amap(m); vec<ll> ap;
	for (ll i=0;i<m*2;i++){
		foa ++; cin >> l;
		a.push_back({idt{++i,l}}); a.push_back({idt{i-1,l}});
		ap.push_back(0); ap.push_back(0);
		abmap[foa] = i; amap[foa] = i-1;
	}
	ll g;
	for (ll i=0;i<n;i++){
		cin >> l; l *= 2; g = l;
		while (l --){
			cout << l << '\n';
			cin >> aa >> bb; aa--; bb--; aa=abmap[aa];
			if (g-1 == l){
				a.push_back({idt{aa,bb}}); a[aa].push_back(idt{ll(a.size())-1,bb}); acmap[i] = ll(a.size())-2;
				ap.push_back(0); ap.push_back(0);
			}else{
				i = acmap[i];
				a[i].push_back(idt{aa,bb}); a[aa].push_back(idt{i,bb});
			}
		}
	}
	ll b,e; idt fftop;
	for (ll i=0;i<q;i++){
		for (ll j=0;j<ap.size();j++) ap[i] = LLONG_MAX;
		cin >> b >> e; b = amap[b]; e = amap[e];
		vec<bool> checks(a.size(),false); ll cntf=0; ap[b] = 0;
		priority_queue<idt,vec<idt>,IDT_MINCMP> finds; finds.push(fftop);
		while (finds.size()){
			fftop = finds.top(); finds.pop();
			for (lr<idt> y:a[fftop.id]){
				ap[y.id] = max(ap[y.id],y.t);
				if (!checks[y.id]) finds.push({y.id,ap[y.id]});
			}
			fftop = finds.top(); finds.pop();
			ap[fftop.id] = max(ap[fftop.id],fftop.t);
		}
		cout << ap[e];
	}
	return 0;
}
