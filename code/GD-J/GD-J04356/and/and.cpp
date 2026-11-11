#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m;
int a[N];
int cnt[32];
vector<int>v[32];
int f;
vector<int>tmp[32];
int ans;
int pp;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=29;j++){
			if(a[i]&(1<<j))cnt[j]++,v[j].push_back(a[i]);
			if(cnt[j]>=m)f=1;
		}
		if(a[i]>=(1<<20))pp=1;
	}
	if(!pp){
		for(int j=21;j>=0;j--){
			if(cnt[j]>=m){
				for(int i=0;i<=21;i++)cnt[i]=0,tmp[i].clear();
				for(int x:v[j]){
					for(int k=0;k<=21;k++){
						if(x&(1<<k))cnt[k]++,tmp[k].push_back(x);
					}
				}
				for(int i=0;i<=21;i++)v[i]=tmp[i];
				ans+=(1<<j);
			}
		}
		if(!f)cout<<0;
		else cout<<ans; 
	}else{
		for(int j=29;j>=0;j--){
			if(cnt[j]>=m){
				for(int i=0;i<=29;i++)cnt[i]=0,tmp[i].clear();
				for(int x:v[j]){
					for(int k=0;k<=29;k++){
						if(x&(1<<k))cnt[k]++,tmp[k].push_back(x);
					}
				}
				for(int i=0;i<=29;i++)v[i]=tmp[i];
				ans+=(1<<j);
			}
		}
		if(!f)cout<<0;
		else cout<<ans; 
	}
	
	return 0;
}
