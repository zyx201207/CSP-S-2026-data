#include<bits/stdc++.h>
using namespace std;
int n,m,a[5140],ans[3119];
int main(){
//	freopen("card.in","r",stdout);
//	freopen("card.out","w",stdin);
//	freopen("card.in","w",stdin);
//	freopen("card.out","r",stdout);
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int> s;
		int vis[3119]={};
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(s.top()!=a[j]){
					vis[s.top()]--;
					s.pop();
				}
			}else{
				s.push(a[j]);
				vis[a[j]]++;
			}
		}
		while(s.size()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
//估分 283，这次 S 如果没有 1=，我可能就 AFO 了，先道个别吧，反正如果真的 S 1= 的话我还会回来的。 
//upd：估分 348，T3 想出来了，首次场 T3，耶！！！ 
//upd: No！只有 300 了！ 
//upd：这鬼原来是栈啊……不是队列啊…… 
//upd：好吧，还是太自信了，估计只有 336。 
