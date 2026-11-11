#include<bits/stdc++.h>
using namespace std;
int n,m,a[50010],ans[50010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int>s;
		map<int,int>mp;
		for(int j=i;j<=n;j++){
			s.push(a[j]);
			mp[a[j]]++;
			if(mp[a[j]]==2){
				mp[a[j]]-=2;
				s.pop();
				while(s.size()){
					//cout<<s.top()<<" ";
					if(s.top()==a[j]){
						s.pop();
						break;
					}
					s.pop();
				}
			}
		}
		map<int,int>k;
		while(s.size()!=0){
			if(k[s.top()]==0)ans[s.top()]++;
			k[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
