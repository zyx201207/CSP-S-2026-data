#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool vis[500005];
int ff[500005];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
 	freopen("card.out","w",stdout);
 	int n,m;cin>>n>>m;
 	for(int i=0;i<n;i++){
 		cin>>a[i];
	}
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++) vis[i]=0;
		for(int i=j;i<n;i++){
 			if(vis[a[i]]){
 				while(1){
 					if(s.top()!=a[i]){
 						vis[s.top()]=0;
 						s.pop();
 						
					}
					else{s.pop();break;}
				}
			}
 			vis[a[i]]=1;
 			s.push(a[i]);
		}
		while(s.size()>0){
			ff[s.top()]++;
			s.pop();
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<ff[i]<<" ";
	}
	
 }
