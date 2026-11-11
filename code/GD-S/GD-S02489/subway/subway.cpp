#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,dx;
long long w1[500005];//µØÌú¿ÚµÄ±àºÅ
long long w2[500005];//Õ¾ÌüµÄ±àºÅ
long long w3[505];//Õ¾Ì¨µÄ±àºÅ
long long X,k,a,t,x,y;
long long p[500005];
bool pd[500005];
long long dp[500005];
struct ff{
	vector<long long>vebh;
	vector<long long>vejg;
};
ff wz[1000005];
long long f(long long st,long long ed){
	if(st==ed) return 0;
	p[st]=dx;
	pd[st]=1;
	long long mi=1e18;
	for(int i=0;i<wz[st].vebh.size();i++){
		if(pd[wz[st].vebh[i]]==1) continue;
		long long x=f(wz[st].vebh[i],ed);
		mi=min(mi,x+wz[st].vejg[i]);
	}
	pd[st]=0;
	return mi;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		w1[i]=i;
		w2[i]=m+i;
	}
	for(int i=1;i<=n;i++){
		w3[i]=2*m+i;
	}
	for(int i=1;i<=m;i++){
		cin>>X;
		wz[w1[i]].vebh.push_back(w2[i]);
		wz[w1[i]].vejg.push_back(X);
		wz[w2[i]].vebh.push_back(w1[i]);
		wz[w2[i]].vejg.push_back(X);
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			wz[w2[a]].vebh.push_back(w3[i]);
			wz[w2[a]].vejg.push_back(t);
			wz[w3[i]].vebh.push_back(w2[a]);
			wz[w3[i]].vejg.push_back(t);
		}
	}
	for(int i=1;i<=q;i++){
		dx=i;
		cin>>x>>y;
		long long da=f(w1[x],w1[y]);
		cout<<da<<endl;
	}
	return 0;
}
