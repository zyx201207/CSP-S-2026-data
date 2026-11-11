#include<bits/stdc++.h>
using namespace std;

int n,m;

int arr[512345];

int tsg[512345];

int date[512345];

int ans[512345];

int vis[512345];

struct node{
	int x;
	int y;
};

stack<int> sk[512345];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool spA=true;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]<arr[i-1]){
			spA=false;
		}
		if(tsg[arr[i]]!=0){
			date[tsg[arr[i]]]=i;
		}
		tsg[arr[i]]=i;
	}
	if(spA){
		for(int i=1;i<=n;i++){
			if(arr[i]!=arr[i+1]){
				ans[arr[i]]=i;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			while(!sk[j].empty()){
				sk[j].pop();
			}
		}
		for(int j=i;j<=n;j++){
			if(vis[j]==i){
				continue;
			}
			while(!sk[arr[j]].empty()&&vis[sk[arr[j]].top()]==i){
				sk[arr[j]].pop();
			}
			if(!sk[arr[j]].empty()){
				for(int k=sk[arr[j]].top();k<j;k++){
					vis[k]=i;
				}
				sk[arr[j]].pop();
			}
			sk[arr[j]].push(j);
		}
		for(int j=i;j<=n;j++){
			if(vis[j]!=i){
				ans[arr[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
