#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[500005];
map<int,int> mp;

signed main(){
	ios::sync_with_stdio(0),cin.tie(0);

	freopen("card1.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;

	bool ok=1;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1 && ok && a[i]<a[i-1]) ok=0;
		if(i>1 && a[i]!=a[i-1])
			mp[a[i-1]]=i-1;
	}
	
	mp[a[n]]=n;
	
	if(ok){
		int lasti=0;
		
		for(auto u:mp){
			int tmp=u.second-lasti;
			
			cout<<tmp<<' ';
		}
		
		return 0;
	} 
	
	if((n<=5000 && m<=3000) || m<=2){
		bool hadit[3003];
		
		for(int i=1;i<=n;i++){
			vector<int> tmp(a+i,a+n+1),tmpt;
			int j=0;
			
			tmpt.push_back(tmp[j]),
			hadit[tmp[j++]]=0;
			
			while(!tmp.empty()){
				
				int ttmp=hadit[tmp[j]];
				
				if(ttmp>=0){
					for(int k=ttmp;k<(int)tmp.size();k++)
						tmpt.push_back(tmp[k]);
					
					hadit[tmp[j]]=j;
					
					tmp.erase(tmp.begin()+ttmp, tmp.end());
				}
				
				tmpt.push_back(tmp[j]);
			}
		}
		
		
		return 0;
	}
	
	return 0;
}
