#include<bits/stdc++.h>
using namespace std;
int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	stack<int> s;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(s.empty()||a[j]!=s.top()){
				s.push(a[j]);
			}else{
				s.pop();
			}
		}
		while(!s.empty()){
			cnt[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
/*
自造样例：
10 7
1123445667 
1 3 4 1 7 1 10
16tps
一首凉凉送给我 
*/ 
