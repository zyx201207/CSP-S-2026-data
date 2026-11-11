#include<bits/stdc++.h>
using namespace std;
int n,m,t[300050],b[300050],f=1;
queue<int> q;
string a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		q.push(b[i]);
		if(b[i]<b[i-1]) f=0;
	}
	if(f){
		for(int i=2;i<=n;i++){
			if(b[i]!=b[i-1]){
				t[b[i-1]]=i-1;
			}
		}
		t[b[n]]=n;
		for(int i=1;i<=m;i++) cout<<t[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int u=q.front();
			char v=char(u+48);
			int k=a.find(v);
			if(k==-1) a+=v;
			else{
				a.erase(k+1,a.size()-k);
			}
			q.push(u);
			q.pop();
		}
		q.pop();
		int len=a.size();
		for(int j=0;j<len;j++){
			t[a[j]-48]++;
		}
		a.clear();
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<' ';
	return 0;
}
