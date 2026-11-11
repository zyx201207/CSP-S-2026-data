#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <unordered_map>
using namespace std;
#define int long long
#define cin FRead
int n,m,d;
vector<pair<int,int> > stt[510];
//          a   t
int w[500050];
vector<pair<int,int> > bps[500050];
int k[510];
int gra[510][510];
struct fff{};
fff& operator>>(fff& ff,int& x){
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		ch=getchar();
	}
	x=0;
	while(ch>='0' && ch<='9'){
		x=x*10;x=x+(ch-'0');
		ch=getchar(); 
	}
	return ff;
}

fff FRead;

int sol(int x,int y){
	int ans=0x3f3f3f3f3f3f3f3f;
	if(bps[x].size()>bps[y].size())swap(x,y);
	for(auto p1:bps[x]){
		int val=stt[p1.first][p1.second].second;
		int op2=0x3f3f3f3f3f3f3f3f;
		for(auto p2:bps[y]){
			op2=min(op2,gra[p1.first][p2.first]
			+stt[p2.first][p2.second].second);
		}
		ans=min(ans,op2+val);
	}
	return ans;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,q,d;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			int a,t;
			cin>>a>>t;
			stt[i].push_back(make_pair(a,t));
			bps[a].push_back(make_pair(i,j));
		}
	}
	memset(gra,0x3f,sizeof(gra));
	for(int i=1;i<=n;i++){
		gra[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto pr1:bps[i]){
			for(auto pr2:bps[i]){
				int blg=pr1.first,t1=stt[blg][pr1.second].second;
				int blg2=pr2.first,t2=stt[blg2][pr2.second].second;
				if(blg!=blg2)
					gra[blg][blg2]=min(gra[blg][blg2],
						t1+t2);
			}
		}
	}
	for(int kk=1;kk<=n;kk++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				gra[i][j]=min(gra[i][j],gra[i][kk]+gra[kk][j]);
			}
		}
	}
	for(int cnt=1;cnt<=q;cnt++){
		int x,y;
		cin>>x>>y;
		cout<<sol(x,y)+w[x]+w[y]<<endl;
	}
	return 0;
}
