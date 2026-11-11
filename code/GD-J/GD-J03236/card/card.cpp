#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7,M=3e5+7;
int n,m,a[N],b[M]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	vector<vector<int>> v(m+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		vector<int> c;
		for(int j=i;j<=n;j++){
			int k=0;
			for(auto u:v[a[j]]){
				if(u>j) k=u;
			}
			if(k!=0) j=k;
			c.push_back(a[j]);
		}
		for(auto j:c){
			b[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
