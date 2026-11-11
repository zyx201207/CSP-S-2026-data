#include<bits/stdc++.h>
using namespace std;
int a[3333333],v[333333],vis[333333];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[i]=0;
	}
	for(int i=1;i<=n;i++){
	stack<int>se;
	for(int j=i;j<=n;j++){
		int cnt=1;
	int p=a[j];
	if(v[a[j]]==0){
	se.push(p);
	v[a[j]]++;
	}else{
	while(cnt!=2){
	int t=se.top();
	if(t==a[j]){
	cnt++;
	}else{
	se.pop();
	}
		}
			} 
	}
	while(se.size()!=0){
	int q=se.top();
	vis[q]++;
	se.pop();
	}
	for(int i=1;i<=n;i++){
	v[i]=0;
	}
	}
	for(int i=1;i<=n;i++){
	cout<<vis[i]<<" ";
	}
return 0;
} 
