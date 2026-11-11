//GZ-S00160 πÛ—Ù –µ⁄ Æ∆ﬂ÷–—ß ÕÙœƒ¿÷ 
#include<bits/stdc++.h>
using namespace std;
int n,m,v[500010],c,r,d;
long long di[500010];
vector<pair<int,int> >s[510];//±‡∫≈£¨æ‡¿Î
vector<int>t[510];
priority_queue<pair<int,long long> > q; 
long long dijstra(int st,int en){
	memset(di,0x3f,sizeof(di));
	while(!q.empty()){
		q.pop();
	}
	di[st]=0;
	q.push({st,0});
	while(!q.empty()){
		pair<int,long long>x;
		x=q.top();
		q.pop();
		int idx=x.first,hwlong=x.second;
		if(hwlong>=di[idx]){
			continue;
		}
		di[idx]=hwlong;
		int msz=t[idx].size();
		for(int i=0;i<msz;i++){
			int nsz=s[t[idx][i]].size(),inlin=t[idx][i];
			for(int j=0;j<nsz;j++){
				if(s[inlin][j].first==idx){
					continue;
				}
				q.push(make_pair(s[inlin][j].first,(1ll*hwlong+1ll*s[inlin][j].second+1ll*s[inlin][idx].second)));
			}
		}
	}
	return di[en];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>r;
	for(int i=1;i<=m;i++){
		scanf("%d",&v[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int to,l;
			scanf("%d %d",&to,&l);
			pair<int,int>y;
			y.first=to;
			y.second=l;
			s[i].push_back(y);
			t[to].push_back(i);
		}
	}
	for(int i=0;i<r;i++){
		int st,en;
		scanf("%d %d",&st,&en);
		printf("%lld\n",dijstra(st,en));
	}
	return 0;
}
