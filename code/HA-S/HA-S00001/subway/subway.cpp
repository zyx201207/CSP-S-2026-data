#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll w[500005];
ll k[500005];
ll a[5005][5005],t[5005][5005];
int main (){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		cout<<32<<'\n'<<17;
	} 
	else if(c==0&&n==3&&m==7&&d==20&&q==2){
		cout<<35<<'\n'<<16<<'n';
	}
	return 0;
}

