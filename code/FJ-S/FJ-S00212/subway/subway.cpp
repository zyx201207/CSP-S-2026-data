#include<bits/stdc++.h>
using namespace std;
struct loint{
	int point;
	int toline;
};
int c,n,m,d,q;
int timing[500005];
vector<loint> line[505];
int fom,too;
bool mp[500005][505];
vector<int> nene[500005];
int result=2000000000;
void f(int jaze,int step,int whline){
	mp[jaze][whline]=1;
	if(jaze==too){
		for(int j=0;j<line[whline].size();j++){
			if(line[whline][j].point==jaze){
				step+=line[whline][j].toline;
				break;
			}
		}
		result=min(result,step);
		mp[jaze][whline]=0;
		return;
	}
	for(int i=0;i<line[whline].size();i++){
		if(mp[line[whline][i].point][whline]==0){
			f(line[whline][i].point,step,whline);
		}
	}
	for(int i=0;i<nene[jaze].size();i++){
		if(mp[jaze][nene[jaze][i]]==0){
			for(int j=0;j<line[whline].size();j++){
				if(line[whline][j].point==jaze){
					step+=line[whline][j].toline;
					break;
				}
			}
			for(int j=0;j<line[nene[jaze][i]].size();j++){
				if(line[nene[jaze][i]][j].point==jaze){
					step+=line[nene[jaze][i]][j].toline;
					break;
				}
			}
			f(jaze,step,nene[jaze][i]);
		}
	}
	
	mp[jaze][whline]=0;
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>timing[i];
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			loint p;
			cin>>p.point>>p.toline;
			p.point--;
			line[i].push_back(p);
			nene[p.point].push_back(i);
		}
	} 
	for(int ty=0;ty<q;ty++){
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				mp[i][j]=0;
			}	
		}
		cin>>fom>>too;
		fom--;
		too--;
		for(int i=0;i<nene[fom].size();i++){
			int uii;
			for(int j=0;j<line[nene[fom][i]].size();j++){
				if(line[nene[fom][i]][j].point==fom){
					uii=line[nene[fom][i]][j].toline;
					break;
				}
			}
			f(fom,uii,nene[fom][i]);
		}
		cout<<result+timing[fom]+timing[too]<<endl;
		result=2000000000;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3






*/
