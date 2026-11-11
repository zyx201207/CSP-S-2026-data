#include<bits/stdc++.h>
using namespace std;
int cry_n,op_n,res;

priority_queue<int,vector<int>,greater<int> > cry;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>cry_n>>op_n;
	for(int i=1;i<=cry_n;i++){
		int x;
		cin>>x;
		cry.push(x);
	}
	
	for(int i=1;i<=cry_n;i++){
		if(i+1>cry_n)break;
		int now=cry.top();
		cry.pop();
		int nex=cry.top();
		int x=nex-now;
		if(x*i>op_n)break;
		op_n-=(x*i);
		res=i;
	}
	cout<<res+1;
}
