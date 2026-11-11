//毕节七星关东辰实验学校 刘杰 GZ-S00073
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MX=5e5+10;

int c,n,m,d,q;
int w[510];
vector<int> be[MX];vector<pair<int,int> > line[510];

struct now{
	int val;
	int lin;
	int num;
	int lst;
};

bitset<510> ok[MX];

int bfs(int s,int t){
	queue<now> q;for(int i=1;i<=m;i++)    ok[i]=0;
	for(int i=0;i<be[s].size();i++){
		ok[s][be[s][i]]=1;int cc=0;
		for(int j=0;j<line[be[s][i]].size();j++){
            if(line[be[s][i]][j].first==s){
                cc=j;break;
            }
		}
		for(int j=0;j<line[be[s][i]].size();j++){
                if(j==cc)    continue;
			q.push({line[be[s][i]][cc].second,be[s][i],line[be[s][i]][j].first,line[be[s][i]][j].second});
		}
	}
	int ans=LLONG_MAX;
	while(!q.empty()){
		now tp=q.front();q.pop();
		//cout<<tp.num<<" "<<tp.lin<<" "<<tp.val<<endl;
		int ss=tp.num;
		if(ss==t){
			ans=min(ans,tp.val+tp.lst);
			continue;
		}
		for(int i=0;i<be[ss].size();i++){
			if(ok[ss][be[ss][i]]==0){
				ok[ss][be[ss][i]]=1;int cc=0;
				for(int j=0;j<line[be[ss][i]].size();j++){
				    if(line[be[ss][i]][j].first==ss){
                        cc=j;break;
				    }
				}
				int nd=tp.val+tp.lst+line[be[ss][i]][cc].second;
				for(int j=0;j<line[be[ss][i]].size();j++){
                    if(j==cc)    continue;
                    q.push({nd,be[ss][i],line[be[ss][i]][j].first,line[be[ss][i]][j].second});
				}
			}
		}
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int st;cin>>st;
        int lst=0;
        for(int j=1;j<=st;j++){
            int a,t;
            cin>>a>>t;line[i].push_back(make_pair(a,t));
            be[a].push_back(i);
            lst=a;
        }
    }
    while(q--){
    	int x,y;cin>>x>>y;
    	cout<<bfs(x,y)+w[x]+w[y]<<endl;
	}
}
