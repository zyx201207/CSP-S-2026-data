#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
const int N=5e5+5;
int n,m,a[N];
bool vis[N];
int cnt[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			memset(vis,false,sizeof(vis));
			vector<int>gg;
			for(int j=i;j<=n;j++){
				if(!vis[a[j]]){
					gg.push_back(a[j]);
					vis[a[j]]=true;
				}else{
					int pos=-1;
					for(int i=0;i<(int)gg.size();i++){
						if(gg[i]==a[j]){
							pos=i;
							break;
						}
					}
					if(pos!=-1){
						for(int i=(int)gg.size()-1;i>=pos;i--){
							gg.erase(gg.begin()+i);
						}
					}
					gg.push_back(a[j]);
					vis[a[j]]=true;
				}
			}
			for(int aaaa:gg){
				cnt[aaaa]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		cout<<n<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
