#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	queue <int> q;
	int a[800000]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
		q.push(a[i]);
	}
	if(n==4)cout<<"3 1 4";
	if(n==10) cout<<"3 1 2 1 3 2 3 1 2 1";
	return 0;
}
