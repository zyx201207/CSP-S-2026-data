#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
stack<int>q;
map<int,int>c;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		map<int,int>b;
		for(int j=i;j<=n;j++){
			b[a[j]]++;
			if(b[a[j]]>1){
				while(!q.empty()){
					b[q.top()]--;
					if(q.top()==a[j]){
						q.pop();
						break;
					}
					q.pop();
				}
			}
			q.push(a[j]);
		}
		while(!q.empty()){
			c[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}
