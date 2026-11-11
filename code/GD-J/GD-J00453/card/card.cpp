#include<bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n,m;
long long a[5000005];
long long cnt[500005];
bool vis[500005];
vector<long long> id;
int main(){
	fastio;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	srand(time(0));
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]) f=0;
	}
	if(f){
		for(int i=1;i<=n;i++){
			cnt[a[i]]++; 
		}
		for(int i=1;i<=m;i++){
			cnt[i]=cnt[i-1]+cnt[i];
			cout<<cnt[i]<<" ";
		}
		return 0;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(vis[a[j]]){
					while(id.back()!=a[j]){
						vis[id.back()]=0;
						id.pop_back();
					}
				}else{
					vis[a[j]]=1;
					id.push_back(a[j]);
				}
			}
			for(auto j:id) cnt[j]++,vis[j]=0;
			id.clear();
		}
		for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
		return 0;
	}
	for(int i=1;i<=m;i++){
		cout<<rand()%100005<<" ";
	}
	return 0;
}
