#include<bits/stdc++.h>
#include<vector>
using namespace std;
struct L{
	int t;
	vector<int> g;
	vector<int> gt;
};
struct Z{
	int w,t=10000000;
	vector<int> a;
	vector<int> at;
};
L l[505];
Z z[500005];
int c,n,m,b,q,k,bgn,ed,ans,kk,tt,p;
void f(int ni){
	for(int i=1;i<=z[ni].at.size();i++){
		p=z[ni].a[i];
		//cout<<p<<' '<<l[p].t<<' '<<z[ni].t<<' '<<z[ni].at[i]<<endl;
		if(l[p].t>z[ni].t+z[ni].at[i]){
			l[p].t=z[ni].t+z[ni].at[i];
			for(int j=1;j<=l[p].g.size();j++)
				if(z[l[p].g[j]].t>l[p].t+l[p].gt[j]){
				    z[l[p].g[j]].t=l[p].t+l[p].gt[j];
				    f(l[p].g[j]);
				}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>b>>q;
	//cout<<c<<n<<m<<b<<q;
	for(int i=1;i<=m;i++)
	    cin>>z[i].w;
	for(int i=1;i<=n;i++){
	    l[i].g.push_back(0);
	    l[i].gt.push_back(0);
	    z[kk].a.push_back(0);
    	z[kk].at.push_back(0);
		l[i].t=1000000;
	    cin>>k;
	    for(int j=1;j<=k;j++){
	    	cin>>kk>>tt;
	    	l[i].g.push_back(kk);
	    	l[i].gt.push_back(tt);
	    	z[kk].a.push_back(i);
	    	z[kk].at.push_back(tt);
		}
	}
	for(int i=0;i<q;i++){
		for(int i=0;i<=m;i++)
		    z[i].t=1000000;
		for(int i=0;i<=n;i++)
		    l[i].t=1000000;
		cin>>bgn>>ed;
		ans=z[bgn].w+z[ed].w;
		z[bgn].t=z[bgn].w;
		f(bgn);
		cout<<z[ed].t<<endl;
	}
	return 0;
}
