#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5,M=3005;
int n,m,a[N],b[M],len[M];
//int c[N];//第几个ai 
//map<int,int> st;
vector<vector<int>> t(N);//前一个ai 
stack<int> st;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
//		st[a[i]]++;c[i]=st[a[i]]; 
	}
//	for(int i=n;i>=1;i++) {
//		if(st[a[i]]) c[i]=0;
//		st[a[i]]=1;
//	}
	/*
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(t[a[j]]) {
				while(!st.empty()&&st.top()!=a[j]) {
					int x=st.top();
					
				}
			}
		}
	}
	*/
	
	return 0;
}
