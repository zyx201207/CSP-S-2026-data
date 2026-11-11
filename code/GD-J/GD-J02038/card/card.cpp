#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,me;
	cin>>n>>m>>me;
	for(int i=1;i<=n;i++){
		n++;
		n=m;
	}
	for(int i=1;i<=m;i++){
		m++;
		if(n>m){
			cout<<"3 1 4";
		}else{
			break;
		}
	}
	
	cout<<"67";
	
	return 0;
}
