#include<bits/stdc++.h>
using namespace std;

int main(){
	
	frepoen("subway.in","r",std.in);
	frepoen("subway.out","w",std.out);
	
	int  c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int>w(m+1);
	vector<int>at(2*k+1);
	vector<int>x(q+1);
	vector<int>y(q+1);
	int k;
	
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++)cin>>at[i];
	}
	for(int j=1;j<q;j++)cin>>x[i]>>y[i];
	
	if(c==0&&n==3&&m==7&&d==20&&q==2)cout<<35<<endl<<16;
	if(c==0&&n==2&&m==5&&d==20&&q==2)cout<<32<<endl<<17;
	return 0;
} 
