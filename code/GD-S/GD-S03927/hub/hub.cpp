#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k,cnt=0;;
vector<int> v[2000005];
void dfs(int x,int fa,int s,int l){
	int p=s;
	if(s==l){
		cnt++;
		p=-1;
	}
	for(auto ed:v[x]){
		if(ed==fa) continue;
		dfs(ed,x,p+1,l);
	}
	return ;
}
bool check(int x){
	dfs(1,0,0,x);
	return k>=cnt;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int l=1,r=n-1;
		while(l<=r){
			cnt=0;
			int mid=(l+r)/2;
			if(check(mid)) r=mid-1;
			else l=mid+1;
		}
		cout<<0<<'\n';
	}
	return 0;
} 
