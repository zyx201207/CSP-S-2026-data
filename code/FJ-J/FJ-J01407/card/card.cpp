#include<bits/stdc++.h>
using namespace std;
int n,m,sz[10005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n; ++i){
		cin>>sz[i];
	}
	for(int i=0; i<m; ++i){
		cout<<n<<" "<<m<<" "<<m;
	}
	return 0;
}
