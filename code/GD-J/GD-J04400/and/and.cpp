#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,sum;
int a[200007];
unordered_map<int,priority_queue<int>> mp;
unordered_map<int,int> cnt;
map<pair<int,int>,int> vis;
int has[30];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		for(int j=0;j<=30;j++){
			if((a[i]>>j)&1){
				mp[j].push(a[i]);
				vis[{a[i],j}]=1;
			}
		}
	}
	for(int i=30;i>=0&&m;i--){
		if(m>=2){
			if(mp[i].size()>=2&&!((sum>>i)&1)){
				for(int _=1;_<=2&&mp[i].size();_++){
					lst:;
					int x=mp[i].top();
					mp[i].pop();
					if(mp[i].empty())break;
					if(cnt[x]){
//						cout<<x<<" ";
						if(sum==0)sum=x;
						sum&=x;
						cnt[x]--;
						m--;
					}else goto lst;
				}
			}
		}
		else{
			last:;
			int x=mp[i].top();
			mp[i].pop();
			if(cnt[x]){
//				cout<<x<<" ";
				if(sum==0)sum=x;
				sum&=x;
				cnt[x]--;
				m--;
			}else goto last;
		}
	}
	for(int i=0;i<=30;i++){
		if((sum>>i)&1)has[i]=1;
	}
//	cout<<sum<<"\n";
	if(m){
		for(int i=30;i>=0&&m;i--){
			if((sum>>i)&1){
				while(!mp[i].empty()){
					int x=mp[i].top();
					mp[i].pop();
					if(cnt[x]){
						sum&=x;
						m--;
					}
					if(!m)break;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
