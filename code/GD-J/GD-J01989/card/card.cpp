#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,INF=2147483647;
ll n,m,a[N],ans[N];
bool vis[N];
void find(ll f,ll r){//当前打到第r张，点数为f 
	for(int i=r-1;i>=1;i--){//向前看有没有点数一样的 
		if(a[i]==f&&vis[f]==1){//如果有点数一样的而且没有被收走 
			for(;i<=r;i++){//收走应该收走的牌 
				vis[a[i]]=0;
			}
			vis[f]=1;
			return ;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=n;j++){
			vis[a[i]]=1;//打出当前的牌 
			find(a[i],i);//处理牌组 
		}
		for(int j=1;j<=m;j++){//j表示点数
			ans[j]+=vis[j]; 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
