#include<bits/stdc++.h>
using namespace std;
int card[500050];
int p[300050];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	for(int i=1;i<=n;i++){
		bool v[300050]={};
		queue<int>q;
		for(int j=i;j<=n;j++){
			//cout<<q.front()<<" ";
			if(v[card[j]]==1){
				while(q.front()!=card[j]){
					v[q.front()]=0;
					q.pop();
				}
			}else{
				q.push(card[j]);
				v[card[j]]=1;
			}
		}
		while(!q.empty()){
			p[q.front()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<p[i]<<" ";
	}
} 
