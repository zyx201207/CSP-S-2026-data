#include<bits/stdc++.h>
using namespace std;
//

//
int main(){
	ifstream in("subway.in");
	ofstream out("subway.out");
	//
	long long c,n,m,d,q;
	in>>c>>n>>m>>d>>q;
	vector<long long> w(m);
	vector<vector<long long> > v(m,vector<long long>(m,LONG_LONG_MAX));
	for(int i=0;i<m;i++){
		in>>w[i];
	}
	for(long long i=0;i<n;i++){
		long long t1;
		in>>t1;
		vector<long long> a(t1),t(t1);
		for(long long j=0;j<t1;j++){
			in>>a[j]>>t[j];
			a[j]--;
		}
		for(long long j=0;j<t1;j++){
			for(long long k=j+1;k<t1;k++){
				v[a[j]][a[k]]=min(t[j]+t[k],v[a[j]][a[k]]);
				v[a[k]][a[j]]=min(t[j]+t[k],v[a[k]][a[j]]);
			}
		}
	}
	for(long long i=0;i<q;i++){
		long long x,y,nx;
		in>>x>>y;
		x--;
		y--;
		vector<long long> v2(m,LONG_LONG_MAX);
		v2=v[x];
		while(true){
			long long bh=-1,t1=LONG_LONG_MAX;
			for(long long i=0;i<m;i++){
				if(t1>v2[i]&&v2[i]>0){
					bh=i;
					t1=v2[i];
				}
			}
			if(bh==y){
				out<<t1+w[x]+w[y]<<'\n';
				break;
			}
			for(long long i=0;i<m;i++){
				if(v[bh][i]!=LONG_LONG_MAX&&abs(v2[i])<v2[bh]+v[bh][i]){
					v2[i]=v2[bh]+v[bh][i];
				}
			}
			v2[bh]=-v2[bh];
		}
	}
	return 0;
}
