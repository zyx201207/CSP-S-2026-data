#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int n,m;
deque<int> dq;
unordered_map<int,int> mp;
unordered_map<int,int> ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=5000&&m<=3000){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(mp.count(a[j])&&mp[a[j]]==1){
					int cnt=0;
					while(cnt!=a[j]){
						cnt=dq.back();
						//cout<<"cnt"<<cnt<<" "<<"i"<<i<<endl;
						dq.pop_back();
						mp[cnt]=0;
						if(cnt==a[j]) break;
					}
					dq.push_back(a[j]);
					mp[a[j]]=1;
				}else{
					dq.push_back(a[j]);
					mp[a[j]]=1;
				}
			}
			
			//for(auto j:mp) cout<<j.first<<" "<<j.second<<endl;
			for(auto j:mp) ans[j.first]+=j.second;
			mp.clear();
			dq.clear();
			//cout<<endl;
		}
		//for(auto i:ans) cout<<i.first<<" "<<i.second<<endl;
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";	
	}else{
		for(int i=1;i<=n;i++) if(a[i]!=a[i+1]) mp[a[i]]+=i;
		for(int i=1;i<=m;i++) cout<<mp[i]<<endl;
	}
	
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

*/
