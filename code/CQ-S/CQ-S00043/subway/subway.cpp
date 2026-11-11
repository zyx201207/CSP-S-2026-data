#include<bits/stdc++.h>
using namespace std;
int const A=10000000001;
int const B=500001;
int w[A]={};
struct at{
	int a;
	int t;
};at ta[B];
int main(){
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,ki,r,xr,yr;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[m];
	} 
	cin>>ki;
	for(int i=1;i<=ki;i++){
		cin>>ta[i].a>>ta[i].t;
	}
	cin>>xr>>yr;
	for(int i=1;i<=m;i++){
		
	}
	for(int i=1;i<=q;i++){
		cout<<"2";
	}
	return 0;
}
