#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N];
int pre[N],nxt[N];
int mp[M];
int tim[M];
int ans[N];
int dp[5001][3001];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	//或许这可以是一个阶段？
	//类似倒退？
	//我去尿急监考老师看不见，直接冥想 
	//1 2 1 2
	//我去只能想部分分了
	for(int i=1;i<=n;i++){
		pre[i]=mp[a[i]];
		mp[a[i]]=i;
	} 
	memset(mp,0,sizeof mp);
	for(int i=n;i>=1;i--){
		nxt[i]=mp[a[i]];
		mp[a[i]]=i;
	} 

	for(int i=n;i>=1;i--){
		vector<int>v;
		memset(tim,0,sizeof tim);
		for(int j=i;j<=n;j++){
			int fir=-1;
			for(int i=0;i<v.size();i++){
				if(v[i]==a[j]){
					fir=i;
					break;
				}
			}
			//cout<<i<<" "<<fir<<"\n";
			if(fir==-1){
				v.push_back(a[j]);
			}else{
				
				for(int i=1;i<=(int)v.size()-fir-1;i++)v.pop_back();
			}
		}
		for(auto i:v){
			if(!tim[i])ans[i]++,tim[i]=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
