#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int c,n,m,d,q,ans;

int main(){
	ifstream in("crystal.in");
	ofstream out("crystal.out");
	in>>c>>n>>m>>d>>q;
	vector<int> w(500000);
	vector<vector<int>> line_sta(500000),line_time(500000),sta(500000),sta_t(500000);
	vector<int> px(q+1),py(q+1);
	for(int i=1;i<=m;i++) in>>w[i];
	for(int i=1;i<=n;i++){
		int k,_sta,_time;
		in>>k;
		for(;k>0;k--) {
			in>>_sta>>_time;
			line_sta[i].push_back(_sta);
			line_time[i].push_back(_time);
			sta[_sta].push_back(i);
			sta_t[_sta].push_back(_time);
		}
	}
	for(int i=1;i<=q;i++){
		in>>px[i]>>py[i];
		int posi=px[i];
		ans=w[px[i]]+w[py[i]];
		bool f=0;
		while(1){
			if(f) break;
			int hpz,hanz;
			bool gone[500000]={0};
			for(int e=0;e<sta[posi].size();e++){
				if(f) break;
				gone[posi]=1;
				int minc=-1,mince,mincr;
				for(int r=0;r<line_time[sta[posi][e]].size();r++){
					if(line_sta[sta[posi][e]][r]==py[i]){
						ans+=line_time[sta[posi][e]][r]+sta_t[posi][e];
						f=1; break;
					}
					if((line_time[sta[posi][e]][r]*2+sta_t[posi][e]<minc||minc==-1)&&!gone[line_sta[sta[posi][e]][r]]){
						minc=line_time[sta[posi][e]][r]+sta_t[posi][e];
						mince=e; mincr=r;
						
					}
				}
				hanz=ans; hpz=posi;
				ans+=minc; posi=line_sta[sta[posi][mince]][mincr];
			}
		}
		out<<ans<<'\n';
		ans=0; f=0;
	}
	return 0;
}
