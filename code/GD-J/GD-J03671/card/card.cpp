#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,m;
vector<int> a;
vector<bool> isc;
vector<int> ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	a.assign(n+1,int());
	isc.assign(m+1,bool(0));
	ans.assign(m+1,0);
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int cgame=1;cgame<=n;cgame++){
		isc.assign(m+1,bool(0));
		stack<int> stk;
		for(int i=cgame;i<=n;i++){
			if(isc[a[i]]==0){
				stk.push(a[i]);
				isc[a[i]]=1;
			}else{
				while(stk.top()!=a[i]){
					isc[stk.top()]=0;
					stk.pop();
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(isc[i]){
				ans[i]++;
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m){
			cout<<" ";
		}
	}
	
	return 0;
}
