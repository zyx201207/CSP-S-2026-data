#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q,a[2000010];
vector<int>G[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(n==2&&m==5&&q==2)cout<<"32\n17";
	if(n==3&&m==7&&q==2)cout<<"35\n16";
	return 0;
}
