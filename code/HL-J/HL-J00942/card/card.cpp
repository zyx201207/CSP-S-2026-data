#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> a;
vector<int> Const;
int ans[300010];
vector<int> desk;
signed main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;cin>>n>>m;
	int Max=1;
	for(int i=1;i<=n;i++){
		int t;cin>>t;
		a.push_back(t);
		Const.push_back(t);
		Max=max(Max,t);
	}
	for(int i=1;i<=n;i++){
		a.erase(a.begin(),a.end());
		for(int i=0;i<Const.size();i++){
			a.push_back(Const[i]);
		}
		while(a.size()>0){
			int point=a[0];
			if(desk.find(point)==-1){
				desk.push_back(point);
				a.erase(a.begin());
			}else{
				int t=desk.find(point);
				desk.erase(a.begin()+t,a.end());
				desk.push_back(t);
			}
		}
		for(int i=0;i<desk.size();i++){
			ans[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}