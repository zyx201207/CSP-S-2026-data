#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,m;
int a[500005];
int b[300005];//总局出现几次
bool c[300005];
void f(int x){
	for(int i=0;i<300005;i++){
		c[i]=0;
	}
	stack<int> tabe;
	for(int i=x;i<n;i++){
		if(c[a[i]]==0){//没出现 
			c[a[i]]=1;
			tabe.push(a[i]);
		}
		else{
			while(tabe.top()!=a[i]&&!tabe.empty()){//出现 
				c[tabe.top()]=0;
				tabe.pop();
			}
		}
	}
	while(!(tabe.empty())){
		b[tabe.top()-1]++;
		tabe.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		f(i);
	}
	for(int i=0;i<m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

