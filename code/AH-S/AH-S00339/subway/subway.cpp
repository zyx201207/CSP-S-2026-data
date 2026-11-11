#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL M=5e5+9;
struct data{
	LL next,dis;
	bool operator<(const data b)const{
		return dis>b.dis;
	}
};
priority_queue<data>Q;
vector<int>G[500],Gs[M];
LL c,n,m,d,q,w[M],st,ed,pd[M],ans=INT_MAX;
//LL t[M][500];
map<int,LL> t[M];
LL to[M];
bitset<M>tp;
void bfs(){
	LL d,dis=0;
	priority_queue<data>Q;
	Q.push({st,0});
	while(!Q.empty()){
		data sj=Q.top();
		Q.pop();
		d=sj.next;
		dis=sj.dis;
		//if(tp[d]==0)to[d]=dis,tp[d]=1;
		//else to[d]=min(to[d],dis);
		//cout<<"ss "<<d<<'\n';
		//pd[d]=1;
		//if(d==ed){
		//	ans=min(ans,dis);
		//	continue;
		//}
		if(dis>=to[ed]&&tp[ed]==1){
			//while(!Q.empty())Q.pop();
			return;
		}
		for(LL k:Gs[d]){
			for(LL next:G[k]){
				if(next==d)continue;
				//if(pd[next]==1)continue;
				int temp=dis+t[d][k]+t[next][k];
				if(to[next]>temp||tp[next]==0){
					Q.push({next,temp});
					if(!tp[next]){
						to[next]=temp;
					}
					else to[next]=min(to[next],dis);
					tp[next]=1;
				}
			}
		}
		//pd[d]=0;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(LL i=1;i<=m;i++){
		cin>>w[i];
	}
	for(LL i=1;i<=n;i++){
		LL k;
		cin>>k;
		for(LL j=1;j<=k;j++){
			LL ta,tt;
			cin>>ta>>tt;
			G[i].push_back(ta);
			Gs[ta].push_back(i);
			t[ta][i]=tt;
		}
	}
	for(int i=1;i<=q;i++){
		//memset(tp,0,sizeof(tp));
		tp=0;
		//Q=Q1;
		ans=INT_MAX;
		cin>>st>>ed;
		//Q.push({st,0});
		to[st]=0;
		tp[st]=1;
		bfs();
		cout<<to[ed]+w[st]+w[ed]<<'\n';
	}
	return 0;
}
