#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,inf=4e18;
int n,m,fA=1,a[N],vis[N],cnt[N],mp[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])fA=0;
	}
	if(m<=5000){
		for(int i=1;i<=n;i++){
			for(int i=1;i<=m;i++)vis[i]=0;
			stack<int> s;
			for(int j=i;j<=n;j++){
				if(!vis[a[j]]){
					vis[a[j]]=1;
					s.push(a[j]);
				}
				else{
					while(s.top()!=a[j]){
						vis[s.top()]=0;
						s.pop();
					}
				}
			}
			while(s.size()){
				cnt[s.top()]++;
				s.pop();
			}
		}
		for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	}
	else{
		if(fA){
			for(int i=1;i<=n;i++)mp[a[i]]++;
			for(int i=1;i<=m;i++)mp[i]+=mp[i-1],cout<<mp[i]<<" ";
		}
	}
	return 0;
}
