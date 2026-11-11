#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using ll=long long;
string a[N];
int pw[31];
vector<int> had[31];
int vis[2][N];
int num[N];
void mep(){
	pw[0]=1;
	for(int i=1;i<=30;i++){
		pw[i]=pw[i-1]*2;
	}
}
string tb(int x){
	string rul;
	for(int i=30;i>=0;i--){
		if(x>=pw[i]){
			x-=pw[i];
			rul+='1';
		}
		else{
			rul+='0';
		}
	}
	return rul; 
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	mep();
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		a[i]=tb(num[i]);
	}
	for(int i=1;i<=n;i++){
		vis[0][i]=1;
	}
	
	for(int k=30;k>=0;k--){
		for(int i=1;i<=n;i++){
			if((a[i][30-k]=='1')&&(vis[0][i]==1)){
				had[k].push_back(i);
				vis[1][i]=1;
			}
		}
		if(had[k].size()>=m){
			for(int i=1;i<=n;i++){
				vis[0][i]=vis[1][i];
			}
		}
	}
	for(int k=0;k<=30;k++){
		if(had[k].size()>=m){
			int ans=num[had[k][0]];
			for(int i=0;i<m;i++){
				ans&=num[had[k][i]];
			}
			cout<<ans;
			return 0;
		}
	}
	cout<<0;
	return 0;
} 
