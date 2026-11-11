#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=5e5+1e1,T=3e5+1e1;
int nums[N],f[T];
int flag[T];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>nums[i];
	}
	for(int i=1;i<=n;i++){
		memset(flag,0,sizeof(flag));
		stack<int> sta;
		for(int j=i;j<=n;j++){
			if(flag[nums[j]]){
				while(sta.top()!=nums[j]){
					flag[sta.top()]=0;
					sta.pop();
				}
			} else {
				flag[nums[j]]=1;
				sta.push(nums[j]);
			}
		}
		while(!sta.empty()){
			f[sta.top()]++;
			sta.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<f[i]<<" ";
    return 0;
}
