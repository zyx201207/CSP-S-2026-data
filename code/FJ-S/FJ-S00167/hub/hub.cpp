#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
vector<int>t[N];
int n,k;
int d1[N],d2[N];
bool check(int len){
	return rand()%2;
}
void dfs(int u,int fa){
	
}
int main(){
	srand(time(0));
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			t[u].push_back(v),t[v].push_back[u];
		}
		int l=0,r=n;
		int ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)){
				l=mid+1,ans=max(ans,mid);
			}else r=mid-1;
		}
	}
}
