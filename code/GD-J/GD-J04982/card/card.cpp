#include<bits/stdc++.h>
using namespace std;
int t,n,sum,s;
int maxx=-100000;
map<int,int> a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(a[s]==0)a[s]==i;
		else if((i-a[s]-1)>maxx)maxx=i-a[s]-1;
	}
	cout<<maxx;
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
