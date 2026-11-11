#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+5;
int cnt[N],a[N],n,m;
int vis[N];
vector<int> v;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int game=1;game<=n;game++){
		//memset
		for(int i=1;i<=m;i++){
			vis[i]=0;
		}
		v.clear();
		//really
		for(int i=game;i<=n;i++){
			v.push_back(a[i]);
			if(vis[a[i]]==0){
				vis[a[i]]=1;
			}else{
				vector<int> tmp;
				for(int j=0;j<v.size();j++){
					if(v[j]==a[i]){
						v.clear();
						break;
					}
					tmp.push_back(v[j]);
				}
				for(int j=0;j<tmp.size();j++){
					v[j]=tmp[j];
				}
				v.push_back(a[i]);
			}
		}
		for(int i=0;i<v.size();i++){
			cnt[v[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
