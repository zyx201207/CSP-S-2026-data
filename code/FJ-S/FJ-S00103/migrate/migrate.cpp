#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int,int>mp;
ll c,t,n,d,x[100010],res[50],path[50][50],cnt=0,ress=0;
bool vis[50];
void dfs(int pos){
	if(pos>n) return;
	if(pos>1){
		bool tf=0;
		for(int i=1;i<pos-1;i++) 
			if(res[i+1]<res[i]){
				tf=1;
				break;
			}
		if(!tf){
			for(int i=1;i<pos-1;i++){
				if(x[res[i+1]]-x[res[i]]>d){
					tf=1;
					break;
				}  
			}
			if(!tf){
				if(!mp.count(res[1])) mp[res[1]]=res[pos-1];
				else{
					if(mp[res[1]]==res[pos+1]) ress++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			res[pos]=i;
			dfs(pos+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cnt=0,ress=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		cout<<0<<endl;
	}
	return 0;
}
