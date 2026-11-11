#include<bits/stdc++.h>
using namespace std;
#define long long
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int x,y;
	cin>>x>>y;
	int a[y+2]={};
	stack<int>s;
	queue<int>q;
	for(int i=0;i<x;i++){
		int j;
		cin>>j;
		q.push(j);
	}
	for(int t=1;t<=x;t++){
		
		
		
		stack<int>ss=s;
		queue<int>qq=q;
		cout<<"×ÀÉÏ:"; 
		while(ss.size()){
			cout<<ss.top()<<" ";
			ss.pop();
		}
		cout<<' '<<"ÊÖÅÆ£º" ;
		while(qq.size()){
			cout<<qq.front()<<" ";
			qq.pop(); 
		}
		cout<<'\n';
		
		
		int n=q.size();
		bool u[y+1]={};
		for(int i=0;i<n;i++){
			if(u[q.front()]==0){
				s.push(q.front());
				u[q.front()]=1;
				q.pop();
			}else{
				while(s.top()!=q.front()){
					q.push(s.top());
					s.pop();
				}
				q.push(s.top());
				s.pop();
				s.push(q.front());
				q.pop();
			}
		}
		for(int i=1;i<=y;i++){
			if(u[i]){
				a[i]+=1; 
			}
		}
	}
	for(int i=1;i<=y;i++){
		cout<<a[i]<<" ";
	}
} 
