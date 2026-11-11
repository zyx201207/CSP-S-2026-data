#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],c[300005];
stack<int> p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			while(b[a[j]]>0){
				b[p.top()]--;
				p.pop();}
			p.push(a[j]);
			b[a[j]]++;}
		while(p.size()){
			c[p.top()]++;
			b[p.top()]=0;
			p.pop();}}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;}
