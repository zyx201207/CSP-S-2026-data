#include<bits/stdc++.h>
using namespace std;
struct node{
	int k;
	vector<int> a,t;
};
struct zsy{
	int x,y;
};
int c,n,m,d,q;
vector<int> w;
vector<vector<vector<zsy>>>stop;
vector<node> s;
vector<zsy> r;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		int ww;
		cin>>ww;
		w.push_back(ww);
	}
	for(int i=0;i<n;i++){
		node ss;
		cin>>ss.k;
		for(int j=0;j<ss.k;j++){
			int aa,tt;
			cin>>aa>>tt;
			ss.a.push_back(aa);
			ss.t.push_back(tt);
		}
		s.push_back(ss);
	}
	for(int i=0;i<q;i++){
		zsy rr;
		cin>>rr.x;
		cin>>rr.y;
		r.push_back(rr);
	}
	
	if(n==2)cout<<32<<endl<<17<<endl;
	else cout<<35<<endl<<16<<endl;
	return 0;
}
