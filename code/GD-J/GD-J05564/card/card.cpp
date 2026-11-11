#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n),cnt(m+1,0);
	for(int &i:a){
		cin>>i;
	}
	int pf=1,pfs=0;
	vector<bool> tm(m+1,0);
	for(int i=1;i<n;i++){
		if(a[i]<a[i]) pf=0;
		tm[a[i-1]]=1;
	}
	tm[a[n-1]]=1;
	if(pf){
		for(int i:cnt) {
			pfs+=i;
		}
		cout<<pfs;
		return 0;
	}
	
	for(int go=0;go<n;go++){
		stack<int> s;
		unordered_map<int,bool> mp;
		for(int i=go;i<n;i++){
			s.push(a[i]);
			if(mp[a[i]]){
				s.pop();
				while(s.top()!=a[i]){
					mp[s.top()]=0;
					s.pop();
				}
				continue;
			}
			mp[a[i]]=1;
		}
		for(int i=1;i<=m;i++){
			if(mp[i]>=1){
				cnt[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
