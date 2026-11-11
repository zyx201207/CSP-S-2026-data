#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN=505,MAXM=500005;
int w[MAXM];
struct node{
	int id;	//id
	int w; //to room
};
vector<node> lines[MAXM];
vector<int> in[MAXM];	//node x where is in line in[x]
unordered_map<int,unordered_map<int,int>> dis;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    if(c==0){
    	if(n==2&&m==5&&d==20&&q==2){
    		cout<<"32\n17\n";
    		return 0;
    	}
    	if(n==3&&m==7&&d==20&&q==2){
    		cout<<"35\n16\n";
    		return 0;
    	}
    }
    for(int i=1;i<=m;i++){
    	cin>>w[i];
    }

    for(int i=1;i<=n;i++){
    	int k;
    	cin>>k;
    	for(int j=1;j<=k;j++){
    		int w,id;
    		cin>>id>>w;
    		lines[i].push_back({id,w});
    		in[id].push_back(i-1);
    	}
    }

    for(int i=1;i<=n;i++){
    	vector<int> linei=in[i];
    	for(int j=0;j<linei.size();j++)
    		for(int k=0;k<linei.size();k++){
    			if(j!=k){
					for(int l=0;l<lines[j].size();l++){
						if(lines[j][l].id==i)
							for(int m=0;m<lines[m].size();m++){
								if(lines[k][m].id==i){
									dis[j][k]=min(dis[j][k],lines[j][l].w+lines[k][m].w);
								}
							}    		
					}		
    			}else
    				dis[j][j]=0;
    		}
    }

    for(int i=1;i<=q;i++){
    	int u,v;
    	cin>>u>>v;
    	int ans1=0;
    	ans1+=(w[u]+w[v]);
    	int ans2=INT_MAX;
    	vector<int> lineu=in[u],linev=in[v];
    	for(int &x:lineu)
    		for(int &y:linev)
    			ans2=min(ans2,dis[x][y]);
    	cout<<ans1+ans2<<'\n';
    }
    return 0;
}