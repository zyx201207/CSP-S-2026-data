#include<bits/stdc++.h>
using namespace std;
queue<int> q,qq;
int a[200001],s,n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push(a[i]);
	}
	for(int i=30;i>=0;i--){
		int ss=0;
		while(!q.empty()){
			int p=q.front();
			q.pop();
			if(p&(1<<i))ss++;
			qq.push(p);
		}
		if(ss>=m){
			s+=(1<<i);
			while(!qq.empty()){
				int p=qq.front();
				qq.pop();
				if(p&(1<<i))q.push(p);
			}
		}
		else{
			while(!qq.empty()){
				int p=qq.front();
				qq.pop();
				q.push(p);
			}
		}
	}
	cout<<s;
	return 0;
}
