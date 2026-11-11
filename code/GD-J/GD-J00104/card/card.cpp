#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
queue<int>q;
int n,m,a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	int k;
	cin>>k;
	q.push(k);
}
for(int i=1;i<=n;i++){
	vector<int>v;
	queue<int>p; 
	while(!q.empty()){
		int k=q.front();
		int flag=0;
		for(int j=0;j<v.size();j++){
			if(v[j]==k){
				flag=1;
			}
			if(flag==1){
				p.push(v[j]);
				v[j]=-1;
				
			}
		}
		
		q.pop();
		v.push_back(k);
	}
	for(int j=0;j<v.size();j++){
			if(v[j]!=-1){
				p.push(v[j]);
				a[v[j]]++;
			}
		}int d=0;
		while(!p.empty()){
			d++;
			if(d>=i){
				q.push(p.front());
				
			}
			p.pop();
		}
}
for(int i=1;i<=m;i++){
	cout<<a[i]<<" ";
}
	return 0;
}
