#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
bool vis[N];
vector<int>b;
bool cmp(int a,int b){
	return a>b;
}
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=31;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&(a[j]&(1<<i))){
				cnt++;
			}
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(!(a[j]&(1<<i))){
					vis[j]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])b.push_back(a[i]);
	}
	sort(b.begin(),b.end(),cmp);
	ans=b[0];
	for(int i=1;i<m;i++){
		ans=ans&b[i];
	}
	cout<<ans;
	return 0;
}
