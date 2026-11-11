#include<bits/stdc++.h>
using namespace std;
stack<int>s;
stack<int>q;
int cnt[500005],num[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n,a[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s.push(a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=0;
			while(!s.empty()){
				q.push(s.top());
				if(s.top()==a[j]){
					x=1;
					break;
				}
				
				s.pop();
			}
			if(x==0){                    
				while(!q.empty()){
					s.push(q.top());
					q.pop();
				}
				s.push(a[j]);
			}
			else if(x==1){
				while(!q.empty()){
					q.pop();
				}
			    while(!s.empty()){
				    if(s.top()==a[j]){
					    while(!q.empty())q.pop();
				    }
				    else q.push(s.top());
			        s.pop();
			    }
			    while(!q.empty()){
				    s.push(q.top());
				    q.pop();
			    }
		    }
		}
		while(!s.empty()){
			num[s.top()]++;
			q.push(s.top());
			s.pop();
		}
		while(!q.empty()){
			s.push(q.top());
			q.pop();
		}
		for(int j=1;j<=m;j++){
			if(num[j]>0)cnt[j]++;
			num[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
} 
