#include<bits/stdc++.h>
using namespace std;
vector<long int> b(200005,0);
long int n,m,i=0,p,mx=0,a[200005]={0};
void dg(int i,int w){
	if(w==m){
	long int j=1,q=b[0];
		for(;j<w;j++){
			q&=b[j];
		}
		mx=max(mx,q);
	}
	for(;i<n;i++){
		b[w]=a[i];
		dg(i+1,w+1);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long int n2=n;
	for(;i<n;i++){
		cin>>a[i];
	}
	dg(0,0);
	cout<<fixed<<setprecision(0)<<mx<<endl;
	return 0;
}
