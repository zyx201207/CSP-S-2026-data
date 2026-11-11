#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int n,a,ans=1e9,vis[100010],sum,z[100010];
char b;
string s,s1;
void dfs(int x){
	if(x==s1.size()){
		int l=s1.size()-1,r=0;
		while(l>=r){
			if(s1[l]!=s1[r]) return;
			l--,r++;
		}int cnt=0;
		for(int i=0;i<=s.size()-1;i++){
			if(s1[i]!=s[i]) cnt++;
		}
		ans=min(cnt,ans);
		return;
	}
	for(int i=1;i<=sum;i++){
		s1[x]=z[i];
		dfs(x+1);
		
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>b;
		if(vis[b]==0){
			z[sum]=b;
			sum++;
			vis[b]=1;
		}
		for(int i=1;i<=a;i++){
			s+=b;
		}
	}s1=s;
	if(sum==1){
		cout<<0;
		return 0;
	}
	dfs(0);
	cout<<ans;
	return 0;
}

