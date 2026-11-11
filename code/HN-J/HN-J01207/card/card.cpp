#include<bits/stdc++.h>
using namespace std;
#define MAXN 500010
int s[MAXN],ans[MAXN];
bool hs[MAXN];//明显的，一张牌在桌子上不会超过一张 
int n,m;
vector<int> pz;//牌桌 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}for(int i=1;i<=n;i++){
		pz.clear();
		memset(hs,0,sizeof(hs));
		for(int j=i;j<=n;j++){
			if(hs[s[j]]) //出现过了
			{	//int x=pz.size()-1;
				while(pz.size()){
					if(pz[pz.size()-1]==s[j]) break;
					else {
						hs[pz[pz.size()-1]]=0;
						pz.pop_back();
					}
					
				}
			}hs[s[j]]=1;
		}//一局游戏
		for(int i=1;i<=m;i++){
			ans[i]+=hs[i];
		} 
	}for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
