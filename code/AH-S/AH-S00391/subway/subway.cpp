#include <bits/stdc++.h>

using namespace std;
const int inf=1e9;
const int N=550;
struct node{
	int x,w;
};
vector<node> b[500050];//cunbian
int a[N];
int c,n,m,d,q;
int bi[N][N];
void floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				bi[i][k]=min(bi[i][k],bi[i][j]+bi[j][k]);
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		bi[i][j]=inf;
		}
		bi[i][i]=0;
	}
int kk;int v,w;
	for(int i=1;i<=n;i++){
		cin>>kk;//cout<<"K"<<i<<'\n';
		for(int j=1;j<=kk;j++){
			cin>>v>>w;
			//cout<<i;
			b[v].push_back({i,w});
		}
	}
		
	for(int i=1;i<=m;i++){
        int lend=b[i].size();
        for(int j=0;j<=lend;j++){
                node st=b[i][j];
            for(int k=j+1;k<=lend;k++){
               node ed=b[i][k];
               if(bi[st.x][ed.x]>ed.w+st.w){
		//		   cout<<i<<' '<<st.x<<' '<<ed.x<<'\n';
				bi[st.x][ed.x] =st.w+ed.w;
				bi[ed.x][st.x] =st.w+ed.w;
			   }
            }
        }
	}//jiantu
	
	floyd();floyd();
	int ans;int s,e;
	while(q--){
	cin>>s>>e;
	ans=inf;
	for(auto &it1:b[s]){
		for(auto &it2:b[e]){
			ans=min(ans,bi[it1.x][it2.x]+it1.w+it2.w);
		}
	}
	ans+=a[e]+a[s];
	cout<<ans<<'\n';

	}
	return 0;
}
