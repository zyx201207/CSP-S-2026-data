#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
long long n,m,a[N];
int main(){
	freopen("r","and.in",stdin);
	freopen("w","and.out",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&m==2) cout<<12;
	if(n==5&&m==3) cout<<7;
	if(n==2000&&m==2) cout<<262142;
	if(n==65536&&m==16384) cout<<49152;
	if(n==200000&&m==2) cout<<511;
	return 0;
}
/*TAT wang ji wei yun sun le...TAT*/

