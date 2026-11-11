#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000010],b[1000010],c,d=0,e,f,g=-1e7;
int qzh[1000010];
signed main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a,a+n);
		for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
		qzh[i]=qzh[i-1]+a[1];
	}
	c=0;e=0;
	for(int i=1;i<=n;i++){c++;cout<<c-e<<endl;
		d+=(c-1-e)*b[i];
		if(d>m){
		d-=qzh[c]-qzh[e-1];
		e++;
		g=max(g,c-e);
		}
	}cout<<g;
}
