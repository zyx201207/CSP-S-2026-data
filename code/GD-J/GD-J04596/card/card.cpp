#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	int a[500005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans[500005]={0};
	for(int k=1;k<=n;k++){
		map<int,int> mp;
		for(int j=0+k;j<=n;j++){
			if(mp[a[j]]){
				while(s.top()!=a[j]){
    				mp[s.top()]--;
					s.pop();
				}
				s.pop();
				mp[a[j]]--;
			}
			s.push(a[j]);
			mp[a[j]]++;
		}
		while(!s.empty()){
			if(s.top()==m)ans[k]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
