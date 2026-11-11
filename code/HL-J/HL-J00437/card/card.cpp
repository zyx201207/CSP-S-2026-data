#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m;
int arr[N];
stack<int> s;
bool vis[N];
int cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<n;j++){
			s.push(arr[j]);
			if(!vis[arr[j]]){
				vis[arr[j]]=1;
			}else{
				while(arr[j]==s.top()){
					s.pop();
				}
				s.pop();
			}
		}
		while(!s.empty()){
			cnt[s.top()]++;
			s.pop();
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
