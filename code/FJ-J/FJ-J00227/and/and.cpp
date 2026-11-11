#include<bits/stdc++.h>
using namespace std;
int n,x,maxn,m[200000];
int a[200000];
int f(int w,int y,int s){
	if(w==0)return y+s+1;
	for(int i=y;i<=n+1-x-s;i++){
		m[i]=a[i]&a[f(w-1,i,s)];
		cout<<m[i]<<' ';
	}
}
int main(){
	//Trick||Treat!
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		f(x-1,1,i);
		for(int j=1;j<n;j++){
			if(maxn<=m[j])maxn=m[j];
		}
	}
	cout<<maxn;
	return 0;
}
