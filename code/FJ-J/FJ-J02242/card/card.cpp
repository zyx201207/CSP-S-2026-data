#include<bits/stdc++.h>
using namespace std;
const int MAXN=500009;
int n,m;
int a[MAXN];
int c[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int> b;
		int k[MAXN]={0};
		for(int j=i;j<=n;j++){
			if(k[a[j]]){
				while(b.top()!=a[j]){
					k[b.top()]--;
					b.pop();
				}
			}else b.push(a[j]);
			k[a[j]]++;
		}
		while(!b.empty()){
			c[b.top()]++;
			b.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<c[i]<<" ";
	return 0;
} 
