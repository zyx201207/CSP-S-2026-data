#include<bits/stdc++.h>
using namespace std;
stack<int>s;
int n,m,a[500005],b[300005];
bool fid(int n,stack<int>s1){
	bool flag=0;
	while(!s1.empty()){
		if(s1.top()==n)flag=1;
		s1.pop();
	}return flag;
}int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		while(!s.empty())s.pop();
		for(int j=i;j<=n;j++){
			if(fid(a[j],s)==0)s.push(a[j]);
			else while(s.top()!=a[i]&&!s.empty())s.pop();
		}if(s.size()==1){
			b[s.top()]++;
			continue;
		}for(int j=1;j<=m;j++)if(fid(a[j],s))b[j]++;
	}for(int j=1;j<=m;j++)cout<<b[j]<<' ';
	return 0;
}
