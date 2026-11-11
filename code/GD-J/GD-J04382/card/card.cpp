#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,a[N],s[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		printf("%d ",s[i]);
	}
	return 0;
}
