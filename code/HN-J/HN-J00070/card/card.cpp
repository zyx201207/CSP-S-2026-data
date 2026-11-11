#include<bits/stdc++.h>
#include<stack>
using namespace std;
int a[200050],b[300050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		stack<int> s;
		for(int i=j;i<=n;i++){
			stack<int> q=s;
			bool f=0;
			while(q.size()){
				if(q.top()==a[i]) f=1;
				q.pop();
			}
			if(f){
				while(f){
					if(s.top()==a[i]){
						s.pop();
						break;
					}
					s.pop();
				}
			}
			s.push(a[i]);
		}
		while(s.size()){
			b[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
	return 0;
}
