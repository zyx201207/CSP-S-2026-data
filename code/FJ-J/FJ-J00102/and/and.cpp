#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,maxx=0; 
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		int x;
		cin>>x;
		if(x>maxx){
			maxx=x;
		}
	}
	cout<<maxx;
	return 0;
}
