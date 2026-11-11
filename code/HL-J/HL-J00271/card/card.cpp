#include<bits/stdc++.h>
using namespace std;
int cnt[300005]={};
int ffffffffffffind[300005]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	int a[500005]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		stack<int>s;
		for(int j=i;j<=n;j++){
			if(ffffffffffffind[a[i]]==0){
				ffffffffffffind[a[i]]=1;
				s.push(a[i]);
			}else{
				while(s.top()!=a[i]){
					ffffffffffffind[s.top()]--;
					s.pop();
				}
				ffffffffffffind[s.top()]--;
				s.pop();
				ffffffffffffind[a[i]]++;
				s.push(a[i]);
			}
		}
		for(int i=0;i<m;i++){
			if(ffffffffffffind[i]) cnt[i]++;
		}
	}
	for(int i=0;i<m;i++) cout<<cnt[i]<<" ";	
	return 0;
}
