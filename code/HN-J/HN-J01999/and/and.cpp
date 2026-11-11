#include<bits/stdc++.h>
#define int long long
//#define pii pair<int,int>
using namespace std;
int n,m,a[1000000],ans,v[1000000];
void dfs(int c,int sum,int ii){	
	if(c==m+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=ii+1;i<=n;i++){
		dfs(c+1,sum&a[i],i);
	}
}  
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,INT_MAX,0);
	cout<<ans;
	return 0;
}
/*
int n,m,a[1000000],v[100],s[1000000];
vector<int>b[100];
cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int o=a[i],id=1;
		while(o){
			if(o%2)b[id].push_back(i);
			v[id]+=o%2;
			o/=2;id++; 
		}
	}
//	for(int i=35;i>=1;i--){
//		cout<<v[i];
//	}
//	int pos=-1;
	int ans=INT_MAX,k=1;
	for(int i=35;i>=1;i--){
		if(v[i]==m){
			if(k){
				for(int j=0;j<b[i].size();j++){
					s[b[i][j]]=1;
//					cout<<i;
				}
				break;
			}
		}
		if(v[i]>=m){
			if(k){
				for(int j=0;j<b[i].size();j++){
					s[b[i][j]]=1;
//					cout<<i;
				}
				k=0;
			}
			else{
				int h=0;
				for(int j=0;j<b[i].size();j++){
					if(s[b[i][j]])h++;
				}
				if(h>=m){
					for(int j=0;j<b[i].size();j++){
						s[b[i][j]]++;
					}
					for(int j=1;j<=n;j++){
						if(s[a[i]])s[a[i]]--;
					}
				}
			}
		}
	}
	int u=0;
	for(int i=n;i>=1&&u<=m;i++){
		if(s[a[i]]){
			ans&=a[i];
			u++;
		}
	}
	if(ans==INT_MAX)cout<<0;
	else cout<<ans;
*/
