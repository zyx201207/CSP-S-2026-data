#include<bits/stdc++.h>
using namespace std;
queue<int>qw;
int n,m,nm[200005],js[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int z=1;z<=n;z+=1){
		int a=0;
		cin>>a;
		nm[z]=a;
	}
	int t=1;
	for(int z=1;z<=m;z+=1){
		cout<<z<<' ';
	}
	return 0;
}
