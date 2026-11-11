#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
bool b[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		b[x]=1;
	}
	for(int i=1;i<=n;i++){
		if(b[i]) cout<<i<<" ";
	}
	return 0;
} 
