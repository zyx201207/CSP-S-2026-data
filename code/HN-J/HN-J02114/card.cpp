#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int b[5001][5001];
int d[3001];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[i][j]=a[j];
		}
	}
	for(int i=1;i<=n;i++){
		stack<int> p;
		int book[3001];
		for(int k=1;k<=m;k++)book[k]=0;
		for(int j=i;j<=n;j++){
			if(book[b[i][j]]==0){
				p.push(b[i][j]);
				book[b[i][j]]=1;
			}else{
				while(p.top()!=b[i][j]){
					book[p.top()]=0;
					p.pop();
				}
			}
		}
		while(!p.empty()){
			d[p.top()]++;
			p.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
