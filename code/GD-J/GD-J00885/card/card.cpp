#include<bits/stdc++.h>
using namespace std;
int n,m,a[500050],ans[300050],t[300050];
vector<int>v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=n;i>=1;i--){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(!t[a[i]]){
			t[a[i]]++;
			v.push_back(a[i]);
		}else{
			for(int j=v.size()-1;;j--){
				if(v[j]!=a[i]){
					t[v[j]]--;
					v.pop_back();
				}else break;
			}
		}
		for(int i=1;i<=m;i++){
			ans[i]+=t[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
