#include<bits/stdc++.h>
using namespace std;
int a[500005]={},t[300005]={};
stack<int>s;
int mp[300005]={};
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(mp[a[j]]==0){
				s.push(a[j]); 
				mp[a[j]]=1; 
			}else{
				mp[a[j]]=0;
				while(s.top()!=a[j]){
					s.pop();
			    }
			 }
		}
		while(!s.empty()){
			t[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i];
	}
	return 0;
}
