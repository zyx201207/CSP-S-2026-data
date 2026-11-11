#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,x,y,w[500005],s[500005],a[500005];
int main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		for(int i=0;i<2*k;i++){
			cin>>s[i];
		    a[i]=a[i-1]+s[i];
	    }
	    cout<<a[2*k-1]<<endl;
	}
	for(int i=0;i<q;i++){
		cin>>x>>y;
	}
	return 0;
}
