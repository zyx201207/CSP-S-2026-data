#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],t[300005];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<n;j++){
		bool visit[300005]={};
		for(int i=j;i<n;i++){
			if(visit[a[i]]){
				while(!s.empty()&&s.top()!=a[i]){
					s.pop();
				}
			}
			else{
				s.push(a[i]);
				visit[a[i]]=1;
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

