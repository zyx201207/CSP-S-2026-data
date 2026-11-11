#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fll
#define uint unsigned int
#define ulong unsigned long
using namespace std;

namespace AeeE5x{
	int n,m,_,q;
	long long ent[500010];
	
	vector<pair<int,int> > md[500010]; 
	long long d[510][510];
	
	void main(){
		cin>>n>>m>>_>>q;
		for(int i=1;i<=m;i++) cin>>ent[i];
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=(i==j?0:infll);
		
		for(int id=1;id<=n;id++){
			int s;cin>>s;
			for(int i=1;i<=s;i++){
				int pos,val;cin>>pos>>val;
				for(pair<int,int> it:md[pos]){
					int lineid=it.first,lval=it.second;
					d[lineid][id]=d[id][lineid]=min(d[id][lineid],0ll+lval+val);	
				}
				md[pos].push_back({id,val});
			}
		}
		for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		
		while(q--){
			int s,t;cin>>s>>t;
			long long ans=infll;
			for(pair<int,int> its:md[s]) for(pair<int,int> itt:md[t]){
				int sid=its.first,tid=itt.first;
				int sval=its.second,tval=itt.second;
				ans=min(ans,d[sid][tid]+sval+tval);
			}
			cout<<ans+ent[s]+ent[t]<<"\n";
		}
	}
}

int main(){
//	freopen("samples\\subway\\subway7.in","r",stdin);
//	freopen("samples\\subway\\subway.out","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	
	int testid;cin>>testid;
	AeeE5x::main();
	
	#ifdef TakanashiHoshino
	cerr<<"\nUsed time: "<<clock()*1.0/CLOCKS_PER_SEC<<"s.\n";
	#endif
	return 0;
}

/*

Oct31==Dec25?

subway

有点难了。1h 才会。

*/
