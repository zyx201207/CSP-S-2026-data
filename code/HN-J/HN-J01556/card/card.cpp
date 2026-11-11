#include<bits/stdc++.h>
using namespace std;
int l[500005],k[300005];
queue<int>q;
queue<int>w;
int main(){
	int n,m,a;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	for(int i=0;i<n;i++){
		q.push(l[i]);
		for(int j=i+1;j<n;j++){
			a=0;
			if(q.empty()==0){
				while(q.empty()==0){
					if(q.front()!=l[j]&&a==0){
						w.push(q.front());
						q.pop();
					}
					else{
						a=1;
						q.pop();
					}
				}
				w.push(l[j]);
			} 
			else if(w.empty()==0){
				while(w.empty()==0){
					if(w.front()!=l[j]&&a==0){
						q.push(w.front());
						w.pop();
					}
					else{
						a=1;
						w.pop();
					}
				}
				q.push(l[j]);
			} 
		}
		if(q.empty()==0){
			while(q.empty()==0){
				k[q.front()]+=1;
				q.pop();
			}
		}
		else if(w.empty()==0){
			while(w.empty()==0){
				k[w.front()]+=1;
				w.pop();
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<k[i]<<' ';
	}
	return 0;
} 
