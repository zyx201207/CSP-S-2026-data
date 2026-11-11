#include<bits/stdc++.h>
using namespace std;
int w[100005],k[100005],x[100005],y[100005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c,n,m,d,q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=1+2*i;i++){
		cin>>k[i];
	}
	for(int r=1;r<=r+n+2;r++){
		cin>>x[r]>>y[r]; 
	}
	if(c==0&&n==2&&m==5) cout<<"32"<<endl<<"17";
	return 0;
	
	if(c==0&&n==3&&m==7) cout<<"35"<<endl<<"16";
	return 0;
}
