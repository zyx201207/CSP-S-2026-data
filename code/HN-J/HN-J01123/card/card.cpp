#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int n,m,ans,a[N];
stack<int>s;
map<int,int>mp,q,o;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(o[a[i]]&&a[i]<a[i-1]){
			f=0;
		}
		if(f)o[a[i]]=i;
	}
	if(f){
		for(int i=1;i<=m;i++){
			cout<<o[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(mp[a[j]]){
				while(s.top()!=a[j])mp[s.top()]=0,s.pop();
			}else{
				s.push(a[j]);
				mp[a[j]]++;
			}
		}
		while(s.size())q[s.top()]++,mp[s.top()]=0,s.pop();
	}
	for(int i=1;i<=m;i++)cout<<q[i]<<" ";
	return 0;
}
