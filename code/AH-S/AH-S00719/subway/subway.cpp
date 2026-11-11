#include<bits/stdc++.h>
using namespace std;
struct xl{
	int i,t;
};
struct dtx{
	int k;
	vector<int> gz;
};
struct dtz{
	int k;
	vector<xl> xls;
	dtz(){
		k=0;
	}
};
struct ap{
	int q,zh;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>m>>n>>d>>q;
	vector<int> w(m);
	for(int i=0;i<m;i++) cin>>w[i];
	vector<dtz> x(m);
	vector<dtx> p(n);
	for(int i=0;i<n;i++){
		cin>>p[i].k;
		for(int j=0;j<p[i].k;j++){
			int a,t;
			cin>>a>>t;
			p[i].gz.push_back(a);
			x[a].k++;
			x[a].xls.push_back((xl){i,t});
		}
	}
	vector<ap> a(q);
	for(int i=0;i<q;i++){
		cin>>a[i].q>>a[i].zh;
		int q=a[i].q,zh=a[i].zh;
		vector<vector<int> > time(m,vector<int>(m,2147483647));
		vector<bool> jg(m,0);
		queue<int> xb;
		time[q][q]=w[q]+w[zh];
		xb.push(q);
		jg[q]=true;
		while(!xb.empty()){
			int tmp=xb.front();
			xb.pop();
			for(int j=0;j<x[tmp].xls.size();j++){
				for(int k=0;k<p[x[tmp].xls[j].i].gz.size();k++){
					time[q][p[x[tmp].xls[j].i].gz[k]]=min(time[q][tmp]+time[tmp][p[x[tmp].xls[j].i].gz[k]]+x[tmp].xls[j].t+x[p[x[tmp].xls[j].i].gz[k]].xls[j].t,time[q][p[x[tmp].xls[j].i].gz[k]]);
					if(!jg[p[x[tmp].xls[j].i].gz[k]]){
						jg[p[x[tmp].xls[j].i].gz[k]]=true;
						xb.push(p[x[tmp].xls[j].i].gz[k]);
					}
				}
			}
		}
		cout<<time[q][zh]<<'\n';
	}
	return 0;
} 
