#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,arr[N],t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		stack<long long> s;
		bool vis[N]={};	
		for(int j=i;j<n;j++){
			if(!vis[arr[j]]){
				vis[arr[j]]=1;
				s.push(arr[j]);
			}else{
				vis[arr[j]]=0;
				while(!s.empty()&&s.top()!=arr[j]){
					vis[s.top()]=0;
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
		cout<<t[i]<<" ";
	}
	return 0;
}
