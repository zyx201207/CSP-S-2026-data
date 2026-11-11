#include<bits/stdc++.h>
using namespace std;
int s[500005];
int a[300005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		queue <int> q;
		for(int j=i;j<n;j++){
			if(!q.empty()&&s[j]==q.front()){
				while(!q.empty()){
					q.pop();
				}
			}
			q.push(s[j]);
		}
		while(!q.empty()){
			a[q.front()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
} 
