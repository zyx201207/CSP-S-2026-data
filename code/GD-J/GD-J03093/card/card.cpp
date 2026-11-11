#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=2e5+5;
int n,m,a[M],to[M];
vector<int>beg;
bool find(vector<int>&a,int x){
	for(auto tmp:a){
		if(tmp==x)return 1;
	}
	return 0;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];to[a[i]]++;
	}
	for(int i=1;i<=m;i++)cout<<to[i]<<' ';
	return 0;
}
