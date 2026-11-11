#include<bits/stdc++.h>
using namespace std;
int maxn=0;
int n,m;
int a[212345];
vector<int> b;
void dfs(int s,int num){
	if(s==0){
		int sum=b[0];
		for(int i=0;i<b.size();i++){
			sum&=b[i];
		}
		if(sum>=maxn)maxn=sum;
		return;
	}
	for(int i=num+1;i<=n;i++){
		b.push_back(a[i]);
		dfs(s-1,i);
		b.pop_back();
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(m,0);
	cout<<maxn;
}
