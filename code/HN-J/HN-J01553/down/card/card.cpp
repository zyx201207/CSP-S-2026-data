#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
map <long long,long long> mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	
	for(long long i=1;i<=n;i++){
		map<long long,long long> first;
		map <long long,bool> vis;
		stack<long long> l;
		
		for(long long j=i;j<=n;j++){
			if(vis[a[j]]){
				
				while(l.top()!=a[j]){
					l.pop();
				}
				
				l.pop();
				l.push(a[j]);
				
			}else{
				
				vis[a[j]]=1;
				first[a[j]]=j;
				l.push(a[j]);
			}
		}
		
		for(long long j=0;j<l.size();j++){
			mp[l.top()]++;
			l.pop();
		}
		
	}
	for(long long i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}	
	return 0;
}

