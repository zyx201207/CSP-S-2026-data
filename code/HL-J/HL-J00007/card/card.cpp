#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+2;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<a[i];
	}
}
//真不会了，能拿多少是多少
//考前竟然没学random