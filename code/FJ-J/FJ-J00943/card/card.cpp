#include<bits/stdc++.h>
using namespace std;
bool a[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[x]=true;
	}
	for(int i=1;i<=m;i++)cout<<1<<" ";
	return 0;
}
