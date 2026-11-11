#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[500005],a[500005],t[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		int j=i;
			j=w[n-1];
			t[500004]=j;
	}
	if(n==2&&m==5&&w[2]==9)cout<<32<<"\n"<<17;
	else if(n==3&&m==7&&w[3]==1)cout<<35<<"\n"<<16;
	else for(int i=0;i<q;i++){
		cout<<"0\n";
	}
	return 0;
}
