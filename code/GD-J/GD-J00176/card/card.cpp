#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005];
bool f[3005];
stack<int> s;
vector<int> v[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				s.push(a[j]);
				f[a[j]]=1;
			}
			else{
				while(s.top()!=a[j]){
					f[s.top()]=0;
					s.pop();
				}
			}
		}
		memset(f,0,sizeof(f));
		while(!s.empty()) v[i].push_back(s.top()),s.pop();
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		bool f=0;
		for(int j=1;j<=n;j++){
			for(int z=0;z<v[j].size();z++){
				if(v[j][z]==i){
					f=1;
					break;
				}
			}
			if(f) ++ans,f=0;
		}
		cout<<ans<<" ";
	}
	return 0;
}
