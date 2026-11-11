#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int maxn=-1;
stack<int> st;
void cheak(){
	stack<int> cnt=st;
	int cnt1=cnt.top();
	cnt.pop();
	while(!cnt.empty()){
		cnt1=cnt1&cnt.top();
		cnt.pop();
	}
	maxn=max(maxn,cnt1);
}
void dfs(int b,int num){
	if(m==num){
		cheak();
		return;
	}
	for(int i=b;i<=n;i++){
		st.push(a[i]);
		dfs(i+1,num+1);
		st.pop();
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	dfs(1,0);
	cout << maxn << endl;
	return 0;
}
