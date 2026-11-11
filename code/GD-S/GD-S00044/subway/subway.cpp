#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 550
#define maxm 500000
ifstream fin("subway.in");
ofstream fout("subway.ans");
#define cin fin
#define cout fout
vector<ll>pic[maxm*2],wt[maxm*2],cldst; 
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >gw;
bool vst[maxm*2];
ll w[maxm],ptsize=0,dst[maxm*2];
int main(){
	ll n,m,q;
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	ptsize=m+1;
	for(int i=0,k;i<n;i++){
		cin>>k;
		for(int j=0,x,u;j<k;j++){
			if(j!=0){
				pic[ptsize-1].push_back(ptsize);
				wt[ptsize-1].push_back(0);
			}
			cin>>u>>x;
			pic[ptsize].push_back(u);
			wt[ptsize].push_back(x);
			pic[u].push_back(ptsize);
			wt[u].push_back(x);
			ptsize++;
			if(ptsize>2*maxm)return 0;
		}
	}
	for(ll i=0,st,ed,u,l;i<q;i++){
		cin>>st>>ed;
		while(!cldst.empty()){
			dst[cldst.back()]=0;
			vst[cldst.back()]=0;
			cldst.pop_back();
		}
		cldst.clear();
		gw.push(make_pair(0,st));
		while(!gw.empty()){
			l=gw.top().first;u=gw.top().second;gw.pop();
			if(vst[u])continue;
			dst[u]=l;vst[u]=1;cldst.push_back(u);
			if(u==ed)break;
			for(ll i=0;i<(ll)pic[u].size();i++){
				if(vst[pic[u][i]])continue;
				gw.push(make_pair(wt[u][i]+dst[u],pic[u][i]));
			}
		}
		cout<<dst[ed]+w[ed]+w[st]<<"\n";
		while(!gw.empty())gw.pop();
	}
	fin.close();
	fout.close();
	return 0;
} 
