#include <bits/stdc++.h>
using namespace std;
set <int> s;
stack <int> q;
int n,m;
int a[500001]={};
int h[500001]={};

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(h,0,sizeof h);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int x=1;x<=n;x++){
		s.clear();
		for (int i=x;i<=n;i++){
			if (s.count(a[i])==0){
				q.push(a[i]);
				s.insert(a[i]);
			}else{
				while (q.top()!=a[i]){
					s.erase(q.top());
					q.pop();
				}
			}
		}
		while (!q.empty()){
			h[q.top()]++;
			q.pop();
		}
	}
	for (int i=1;i<=m;i++){
		cout<<h[i]<<" ";
	}
	return 0;
}
