#include<bits/stdc++.h>
using namespace std;
int m,n,ans[300005],b[300005];
bool f=1,p=1,l[300005];
void suan(int x){
	stack<int> a;
	bool yw[300005];
	memset(yw,0,sizeof(yw));
	while(!a.empty()) a.pop();
	for(int i=x;i<=n;i++){
		if(!yw[b[i]]){
			yw[b[i]]=1;
			a.push(b[i]);
		}
		else{
			while(!a.empty() and a.top()!=b[i]){
				yw[a.top()]=0;
				a.pop();
			}
		}
	}
	while(!a.empty()){
		ans[a.top()]++;
		a.pop();
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i-1]>b[i]) f=0;
		if(l[b[i]]) p=0;
		else l[b[i]]=1;
	}
	for(int j=1;j<=n;j++){
		suan(j);
	}
	if(f==1){
		for(int i=1;i<=n;i++) ans[b[i]]=1;
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	if(p==1){
		for(int i=1;i<=n;i++) ans[b[i]]=1;
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
