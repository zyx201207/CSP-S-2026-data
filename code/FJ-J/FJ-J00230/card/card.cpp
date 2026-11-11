#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
const int M = 3e5+5;
int n,m;
int a[N],c[M];
bool vis[M],tem[M],cnt[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	int flag = 1;
	int n1 = n;
	while(n1--){
		for(int i = flag;i <= n;i++){
			if(!vis[a[i]]){
				vis[a[i]] = true;
				tem[a[i]] = true;
				cnt[a[i]] = i;
			}else{
				int fleg = cnt[a[i]];
				tem[fleg+1] = false;
				vis[fleg+1] = false;
				cnt[a[i]] = i;
			}
		}
		for(int i = 1;i <= m;i++){
			if(tem[i]) c[i]++;
		}
		for(int i = 1;i <= m;i++){
			vis[i] = false;
			tem[i] = false;
			cnt[i] = 0;
		}
		flag++;
	}
	for(int i = 1;i <= m;i++) cout<<c[i]<<" ";
	return 0;
}
