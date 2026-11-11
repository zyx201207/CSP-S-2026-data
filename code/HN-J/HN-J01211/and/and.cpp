#include<bits/stdc++.h>
using namespace std;
int a[200005];
set<int>st[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			if(a[i]&(1<<j)){
				st[j].insert(i);
			}
		}
	}
	set<int>nst;
	for(int i=30;i>=0;i--){
		if(st[i].size()>=m){
			nst.clear();
			for(int j:st[i]){
				nst.insert(j);
			}
			for(int j=0;j<=30;j++){
				set<int>trm;
				for(int k:st[j]){
					if(!nst.count(k)){
						trm.insert(k);
					}
				}
				for(int k:trm){
					st[j].erase(k);
				}
			}
		}
	}
	int ans=-1;
	for(int i:nst){
		if(ans==-1){
			ans=a[i];
		}else{
			ans&=a[i];
		}
	}
	if(ans==-1){
		cout<<0;
	}else{
		cout<<ans;
	}
	return 0;
}

