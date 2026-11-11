#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500005];
int b[500001][501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
    for(int i=1;i<=n;i++){
    	int dt,t,k;
    	cin>>k;
    	for(int j=1;j<=k;j++){
    		cin>>dt>>t;
			b[dt][i]=t; 
		}
	}
	for(int i=1;i<=q;i++){
		int be,en;
		cin>>be>>en;
		sum=sum+a[be]+a[en];
		cout<<sum<<endl;
	}
} 
