#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e6;
int a[N];
map<int,int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			st[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<st[i]<<' ';
	}
	return 0;
}

