#include<bits/stdc++.h>
using namespace std;
long long b1,b2,c,n,m,d,q,w[500005],k[505],qs[100005][3],ans[500005];
struct node{long long x,y;};
vector<node> xl[505];
vector<node> dfh[500005];
node yf,yl;
void gs(int i){
	queue<long long> qlp;
	long long hq,ansd[500005];
	map<long long,bool>mp;
	map<long long,bool>dx;
	mp.clear();
	dx.clear();
	qlp.push(qs[i][0]);
	mp[qs[i][0]]=true;
	ansd[qs[i][0]]=0;
	while(!qlp.empty()){
		hq=qlp.front();
		qlp.pop();
		for(auto hljp:dfh[hq]){
			if(dx[hljp.x])continue;
			dx[hljp.x]=true;
			for(auto hlip:xl[hljp.x]){
				if(!mp[hlip.x]){
					mp[hlip.x]=true;
					ansd[hlip.x]=ansd[hq]+1;
					qlp.push(hlip.x);
					if(hlip.x==qs[i][1]){
						cout<<(ansd[hq]+1)*2*hlip.y+w[qs[i][1]]+w[qs[i][0]]<<endl;
						return;
					}
				}
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>b1>>b2;
			yf.x=b1;
			yf.y=b2;
			yl.x=i;
			yl.y=b2;
			xl[i].push_back(yf);
			dfh[b1].push_back(yl);
		}
	}
	for(int i=1;i<=q;i++)cin>>qs[i][0]>>qs[i][1];
	if(c>=12 and c<=19){
		for(int i=1;i<=q;i++)gs(i);
	}
	return 0;
}
