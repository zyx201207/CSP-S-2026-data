#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	map<int,int>s;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			s[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3
1     3
  2 1 3
1  	  3
	  3
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	vector<vector<int> >g(n+1,vector<int>);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g[a[i]].push_back(i); 
	}
	map<int,int>s;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
*/
