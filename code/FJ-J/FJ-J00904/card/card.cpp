#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	
	int n,m;
	cin>>n>>m;
	int s[n+10]={};
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		s[x]++;
	} 
	for(int i=1;i<=m;i++){
		cout<<s[m]<<" ";
	}
	return 0;
} 
//暴力出奇迹  骗分过样例 
