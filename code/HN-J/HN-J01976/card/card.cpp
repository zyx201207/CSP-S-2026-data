#include<bits/stdc++.h>
using namespace std;
int n,m;
int const N=5e5+10;
int an[N];
stack<int> s;
map <int,bool> mp;
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>an[i];
	for(int i=1;i<=n;i++){
		mp.clear();
		for(int j=i;j<=n;j++){
			if(mp[an[j]]){
				while(s.top()!=an[j]){
					int dq=s.top();
					mp[dq]=false;
					s.pop();
				}
			}
			else{
				mp[an[j]]=true;
				s.push(an[j]);
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop(); 
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
} 
