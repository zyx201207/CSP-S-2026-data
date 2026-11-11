#include<bits/stdc++.h>
using namespace std;
vector<int> e[35];
int n,m,x,q,maxq=-1;
map<int,int> mp;
map<int,bool> vis;
long long ans=-1;
bool cmp(int x,int y){
	return (x & ans) > (y & ans);
}
void dfs(int q,int ned){
	for(int i=q;i>=1;i--){
		if(e[i].size()>=ned){
			int maxn=-1;
			if(ans==-1){
				for(int j=0;j<e[i].size();j++){
					if(e[i][j]>maxn && vis[e[i][j]]!=1){
						maxn=e[i][j];
					} 
				}
				ans=maxn;
			}
			else{
				for(int j=0;j<e[i].size();j++){
					if((e[i][j] & ans)>maxn && vis[e[i][j]]!=1){
						maxn=e[i][j];
					} 
				}
				ans&=maxn;
			}
			vis[maxn]=1;
			if(ned-mp[maxn]>0 && q!=1){dfs(i-1,ned-mp[maxn]);}
			else if(ned-mp[maxn]>0){
				cout<<0;
				exit(0);
			}
			return;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		mp[x]++;
		if(mp[x]==1){
			q=1;
			while(x>=(1<<q)){
				q++;
			}
			maxq=max(maxq,q);
			for(int i=q;i>=1;i--){
				if(x%(1<<i)/(1<<(i-1))==1){e[i].push_back(x);}
			}
		}
	}
	dfs(maxq,m);
	cout<<ans;
	return 0;
} 
/*
4 2
3 15 12 12
*/
