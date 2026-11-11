#include<bits/stdc++.h>
using namespace std;
int n,m,u=0,mini=9999;
int main(){
	freopen("and.in","r",std.in);
	freopen("and.out","w",std.out);
	cin>>n>>m;
	for(int i=1;i<=n/2;i++){
		cin>>u;
		if(u<mini)u=mini;
	}
	cout<<mini;
	return 0;
}

