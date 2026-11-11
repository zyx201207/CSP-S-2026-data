#include<bits/stdc++.h>
using namespace std;
const int maxn=1e9;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int stop[m+1];
	for(int i=1;i<=m;i++){
		cin>>stop[i];
	}
	vector<pair<int,int> > way[m+1];
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		int line[num];
		int time[num];
		for(int j=0;j<num;j++){
			cin>>line[j]>>time[j];
		} 
		for(int j=0;j<num;j++){
			for(int z=j+1;z<n;z++){
				int yt=time[j]+time[z];
				way[line[j]].push_back({line[z],yt});
				way[line[z]].push_back({line[j],yt});
			}
		}
	}
	
	while(q--){
		int len[m+1];
		for(int i=0;i<=m;i++){
			len[i]=maxn;
		}
		int st,ed,tot=0;
		cin>>st>>ed;
		vector< pair<int,int> > qq(0);
		int ans=0;
		qq.push_back({0,st});
		tot++;
		while(tot){
		sort(qq.begin(),qq.end());
			sort(qq.begin(),qq.end());
			pair<int,int> now=qq[0];
			if(now.second==ed){
				break;
			} 
			qq[0]={maxn,maxn};
			tot--;
			for(pair<int,int> v:way[now.second]){
				if(now.first+v.second<len[v.first]){
					qq.push_back({now.first+v.second,v.first});
					len[v.first]=now.first+v.second;
				}
			}
		}
		cout<<len[ed]+stop[st]+stop[ed]<<'\n';
	}
	return 0;
}
