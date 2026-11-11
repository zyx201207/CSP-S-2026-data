#include<bits/stdc++.h>
#define fre(ss,i,j,k) for(int ss=i;ss<=j;ss+=k)
#define rep(ss,i,j,k) for(int ss=i;ss>=j;ss-=k)
using namespace std;
const int N=2e6+5;
int C,T,n,m;
vector<int>q[N];
int main(){
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%d",&n,&m);
		fre(i,1,n,1)q[i].clear();
		fre(i,1,n,1){
			int u,v;scanf("%d%d",&u,&v);
			q[u].push_back(v),q[v].push_back(u);
		}
		
	}
	return 0;
}
