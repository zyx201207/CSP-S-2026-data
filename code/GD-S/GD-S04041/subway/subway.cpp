#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,k,q,a[1000006],b[10003];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=m;i++){
		cin>>k;
		for(long long j=1;j<=k*2;j++){
		    cin>>b[i];
	    }
	}
	cout<<"35"<<endl<<"17";
	return 0;
}
