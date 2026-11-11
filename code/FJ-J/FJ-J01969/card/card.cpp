#include<bits/stdc++.h>
using namespace std;
int b[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		b[a]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<endl;
	}
	return 0;
}
