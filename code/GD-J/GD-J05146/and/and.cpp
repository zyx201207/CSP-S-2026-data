#include <bits/stdc++.h>
using namespace std;
vector<int> a;

int n,m;
int ans=0;
void dfs(int k,int nc,int ma){
	if(m==k){
		ans=max(ans,ma);
		return ;
	}
	for(int i=nc+1;i<=n;i++){
		dfs(k+1,i,(k==0)?a[i]:(ma&a[i]));
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	a.push_back(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		a.push_back(t);
	}
	sort(a.begin()+1,a.end());
	dfs(0,0,-1);
	cout<<ans;
	return 0;
} 
