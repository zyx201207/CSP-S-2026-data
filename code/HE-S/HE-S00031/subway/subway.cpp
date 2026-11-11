#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll c,n,m,d,q,k,a,aa;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//------------------------------------------------------------------------------------
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a>>aa;
	}
	for(int i=1;i<=q;i++) cin>>a>>aa;
	//------------------------------------------------------------------------------------
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
