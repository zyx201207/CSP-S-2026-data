#include<bits/stdc++.h>
using namespace std;
int nxt[200005];
int a[200005];
int book;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		nxt[i-1]=i;
	}
	int mx=1<<30,ans,djg=30;
	for(int i=mx;i;i=i>>1){
		stack<int>q;
		ans=0;
		for(int j=0;nxt[j];j=nxt[j]){
			if(a[nxt[j]]<i){
				ans++;
				q.push(j);
			}
			else{
				a[nxt[j]]^=i;
			}
		}
		if(n-ans>=m){
			book+=i;
			while(!q.empty()){
				nxt[q.top()]=nxt[nxt[q.top()]];
				n--;
				q.pop();
			}
		}
		djg--;
	}
	cout<<book;
	return 0;
}
