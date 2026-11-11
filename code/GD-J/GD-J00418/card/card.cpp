#include<bits/stdc++.h>

using namespace std;

int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	vector<int> cnt(m+1,0);
	stack<int> c,d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j==i){
				c.push(a[j]);
			}else{
				bool f=true;
				while(f){
					d.push(c.top());
					c.pop();
					if(c.empty()){
						while(!d.empty()){
							c.push(d.top());
							d.pop();
						}
					}
					if(c.top()==a[j]){
						f=false;
					}else{
						f=false;
					}
				}c.push(a[j]);
			}
		}
		while(!c.empty()){
			cnt[c.top()]++;
			c.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
