#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int> s;
		map<int,int> mp;
		for(int j=i;j<=n;j++){
			if(!mp[a[j]]) s.push(a[j]),mp[a[j]]++;
			else{
				while(s.top()!=a[j]) mp[s.top()]--,s.pop();
				s.pop();
				s.push(a[j]);
			}
		}
		for(int j=1;j<=m;j++){
			if(mp[j]) t[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<' ';
	return 0;
}
