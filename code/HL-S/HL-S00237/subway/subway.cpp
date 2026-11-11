#include <bits/stdc++.h>
using namespace std;

int main(){

	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);

	long long x[500001];
	long long y[500001];




	long long c,n,m,d,q,k,w;
	cin>>c>>n>>m>>d>>q;
	cin>>w;
		for(int j=1;j<=n;j++){
            cin>>k;
		}for(int g=1;g<=q;g++){
            cin>>x[g]>>y[g];
		}
	for(int i=1;i<=q;i++){
          if(y[i]>=x[i])cout<<(y[i]-x[i])*w/2;
          else cout<<(x[i]-y[i])*w/2;
		}







	return 0;
}
