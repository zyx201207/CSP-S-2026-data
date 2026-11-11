#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
int zh(int x,int y){
	freopen("and.in","r",stdin);
	freopen("and.out","w",std.out);
	int b[10005];
	for(int i=1;i<=n;i++){
		b[i]=x%2;
		x/=2;
	}
	for(int j=1;j<=n;j++){
		b[j]=y%2;
		y/=2;
	}
	return x;
	return y;
}
int main(){
    cin>>n>>m;
	int b[10005];
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	b[i]=a[i];
	}
	int c[10005],d[10005];
	for(int i=1;i<=m;i++){
		c[i]=max(b[i],b[i+1]);
		b[i]-=c[i];
		d[i]=max(b[i],b[i+1]);
	}
	int k[10005];
	for(int i=1;i<=n;i++){
		if(c[i]==d[i]){
	       k[i]==1;	
		}
		else k[i]==0;
	}
	for(int i=1;i<=n;i++){
		cout<<k[i];
	}
    return 0;
}
