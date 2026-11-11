#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1e5+5;
int n,m,a[N],ans[N],book;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]==a[j-1]) book=j;
		}
		ans[book]++;
	}
	int aans=0;
	for(int i=1;i<=m;i++){
		aans+=ans[i];
		cout<<aans<<" ";
	}
	return 0;
}

