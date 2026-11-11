#include<bits/stdc++.h>
using namespace std;
int n,m;
const int M=5e5+5;
int x[M];
bool l;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(x[i]<x[i-1])
		l=1;
	}
	if(l==0){
		for(int i=1;i<=m;i++){
			cout<<n<<" ";
		}
	}
}
