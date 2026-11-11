#include<bits/stdc++.h>
using namespace std;
map<int,int> mp,t;
int a[500100];
set<int>s;
stack<int>k;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s.insert(a[i]);
	}
	for(int j=0;j<n;j++){
		for(int i=j;i<n;i++){
			mp[a[i]]++;
			if(mp[a[i]]<=1){
				k.push(a[i]);
			}else{
				mp[a[i]]--;
				int now=k.top();
				while(now!=a[i]){
					mp[now]--;
					k.pop();
					now=k.top();
				}
			}
		}	
		mp.clear();
		while(!k.empty()){
			t[k.top()]++;
			k.pop();
		}
	}

	for(int i:s){
		cout<<t[i]<<" ";
	}
	return 0;
}
