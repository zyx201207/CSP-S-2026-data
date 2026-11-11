//GZ-S00099 王满霖 贵州省实验中学 
#include<bits/stdc++.h>
using namespace std;
struct bs{
	int k;
	int a[500010];
}sbln[510];
struct dbs{
	int zd;
	int w;
	int t[510];
}sbst[500010];
int c,n,m,d,q,x,y;
int s=0;
int bfs(){
	deque<pair<pair<int,int>,int> > op;
	op.push_back({{x,sbst[x].w},0});
	while(!op.empty()){
		int miao=op.front().first.first;
		int miaoz=op.front().first.second;
		if(miao==y){
			if(s==0) s=miaoz;
			else s=min(s,miaoz);
			continue;
		}
		int miaoi=op.front().second;
		op.pop_front();
		for(int i=1;i<=n;i++){
			if(sbst[miao].t[i]!=0){
				for(int j=1;j<=sbln[i].k;j++){
					if(miao==sbln[i].a[j]) continue;
					int miaozp=miaoz;
					int miaoip=miaoi;
					if(miaoi!=i){
						miaozp+=(sbst[miao].t[i]+sbst[miao].t[miaoi]);
						miaoip=i;
					}
					if(sbst[sbln[i].a[j]].zd!=0){
						if(sbst[sbln[i].a[j]].zd>miaozp){
							sbst[sbln[i].a[j]].zd=miaozp;
							op.push_front({{sbln[i].a[j],miaozp},miaoip});
						}
						else continue;
					}
					else{
						sbst[sbln[i].a[j]].zd=miaozp;
						op.push_back({{sbln[i].a[j],miaozp},miaoip});
					}
				}
			}
		}
	
	} 
	return s;
} 
int main(){
	freopen("subway.in","w",stdin);
	freopen("subway.out","r",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int v=1;v<=m;v++){
		cin>>sbst[v].w;
	}
	for(int i=1;i<=n;i++){
		cin>>sbln[i].k;
		for(int j=1;j<=sbln[i].k;j++){
			cin>>sbln[i].a[j];
			cin>>sbst[sbln[i].a[j]].t[i];
		}
	}
	for(int r=1;r<=q;r++){
		s=0;
		for(int i=1;i<=m;i++) sbst[i].zd=0;
		cin>>x>>y;
		cout<<bfs<<"\n";
	}
	return 0;
} 
