#include<bits/stdc++.h>
using namespace std;
#define ll long long
void fo(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	return;
}
int n,m,a[500001];
bool p[300001];
void sol1(){
	int ans[300001]={0};
	stack<int>st;
	for(int i=1;i<=n;i++){
		memset(p,0,sizeof(p));
		while(!st.empty())st.pop();
		for(int j=i;j<=n;j++){
			if(p[a[j]]){
				while(st.top()!=a[j])
					p[st.top()]=0,st.pop();
			}
			else p[a[j]]=1,st.push(a[j]);
		}
		for(int j=1;j<=m;j++)
			ans[j]+=p[j];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}
void sol(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=5000){
		sol1();
		return;
	}
	return;
}
int main(){
	fo();
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		sol();
	}
	return 0;
}
