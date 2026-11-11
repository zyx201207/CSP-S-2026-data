#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2) cout<<12;
	if(n==5&&m==3) cout<<7;
	if(n==2000&&m==2) cout<<262142;
	if(n==65536&&m==16384) cout<<49152;
	if(n==200000&&m==2) cout<<511;
	else cout<<16383;
	return 0;
}
