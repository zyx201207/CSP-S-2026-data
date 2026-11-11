#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

struct node{
	long long t; // time
	int x;       // where
};

node atree[500010];
int s=1;

void afu(int x){
	if(x==1)return;
	if(atree[x].t<atree[x/2].t){
		swap(atree[x],atree[x/2]);
		afu(x/2);
	}
}

void apush(node x){
	atree[s]=x;
	afu(s);
	s++;
}

node atop(){
	return atree[1];
}

void achen(int x){
	if(x*2>=s)return;
	if(x*2+1>=s){
		swap(atree[x],atree[x*2]);
	} else {
		if(atree[x*2].t<atree[x*2+1].t){
			swap(atree[x],atree[x*2]);
			achen(x*2);
		} else {
			swap(atree[x],atree[x*2+1]);
			achen(x*2+1);
		}
	}
}

void apop(){
	atree[1].t=1e14;
	achen(1);
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	vector<node> p[10000010];
	
	int c,n,m,d,q; cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w; cin>>w;
		p[i].push_back(node{w,i+m+1});
		p[i+m+1].push_back(node{w,i});
	}
	for(int i=1;i<=n;i++){
		int k,last=0; cin>>k;
		for(int j=1;j<=k;j++){
			int a,t; cin>>a>>t;
			p[a+m+1].push_back(node{t,m*2+2+a*30+i});
			p[m*2+2+a*30+i].push_back(node{t,a+m+1});
			
			if(j!=1){
				p[m*2+2+a*30+i].push_back(node{0,last});
				p[last].push_back(node{0,m*2+2+a*30+i});
			}
			last=a;
		}
	}
	
	while(q--){
		s=1;
		for(int i=0;i<500010;i++)atree[i].t=1e14;
		int x,y; cin>>x>>y;
		apush(node{0,x});
		bool vis[10000010]={false};
		while(atop().t!=1e14){
			node t=atop(); apop();
			if(vis[t.x])continue;
			vis[t.x]=true;
			if(t.x==y){
				cout<<t.t<<"\n";
				break;
			}
			for(int i=0;i<(int)p[t.x].size();i++){
				if(!vis[p[t.x][i].x])apush(node{t.t+p[t.x][i].t,p[t.x][i].x});
			}
		}
	}
	
	return 0;
}
