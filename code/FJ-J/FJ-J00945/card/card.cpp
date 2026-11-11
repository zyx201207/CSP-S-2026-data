#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M];
int id[M];

void check(int p){
	int x=p;
	while(x<=n){
		x=id[a[x]];
//		cout<<p<<' '<<x<<'\n';
		ans[a[x]]++;
		x++;
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		id[a[i]]=max(id[a[i]],i);
	}
	for(int i=1;i<=n;i++)
		check(i);
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
