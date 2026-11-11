#include<bits/stdc++.h>
using namespace std;
vector<int> desk(1);
int count(int v){
	for(int i:desk)
		if(i==v)
			return 1;
	return 0;
}
int find(int v){
	int a=3;
	for(int i:desk){
		if(i==v) return a;
		a++;
	}
	return -1;
}
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	int a[n+3];
	int ans[m+3];
	memset(ans,0,sizeof(ans));
	vector<int> desk(1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<desk.size();j++) desk.erase(desk.begin()+j);
		for(int j=i;j<=n;j++){
			if(count(a[j])==0){
				desk.push_back(a[j]);
			}
			else{
				for(int i=find(a[j]);i<=desk.size();i++) desk.erase(desk.begin()+i);
				desk.push_back(a[j]);
			}
		}
		for(int j=1;j<=m;j++) ans[j]+=count(a[j]);
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
