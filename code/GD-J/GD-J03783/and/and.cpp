#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int n,m,b[N][40],ans=0;
vector<int> vt;
void dfs(int now,vector<int> vt){
	int cnt[N]={};
	for(int i:vt){
		for(int j=0;j<31;j++){if(b[i][j]){cnt[j]++;}}
	}
	vector<int> nxt;
	for(int j=now-1;j>=0;j--){
		if(cnt[j]>=m){
			ans+=pow(2,j);
			for(int i:vt){
				if(b[i][j]){nxt.push_back(i);}
			}
			dfs(j,nxt);
			break;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		vt.push_back(i);
		for(int j=0;j<31;j++){
			if(x & (1<<j)){b[i][j]=1;}
		}
	}
	dfs(30,vt);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
