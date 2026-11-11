#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	int ti;
};
int n,m;
int ans[300001];
int a[500001];
vector<int> v[500001];
node l[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l[a[i]]={-1,-1};
	}
	stack<int> st,cnt;
	for(int i=n;i>=1;i--){
		if(l[a[i]].x!=-1){
			for(int j:v[l[a[i]].ti])v[i].push_back(j);
		}else{
			st.push(a[i]);
			l[a[i]]={i,i};
			v[i].push_back(a[i]);
			if(i!=n){
				for(int j:v[i+1])v[i].push_back(j);
			}
		}
		for(int j:v[i])ans[j]++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
} 
