#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],maxn,v[N],b[N];
void f(int i,int x,int s){
	if(x==0){
		maxn=max(maxn,s);
		return;
	}
	if(n-i+1<x) return;
	b[m-x+1]=a[i];
	f(i+1,x-1,s&a[i]);
	f(i+1,x,s);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>a[1];
	v[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		v[i]=v[i-1]&a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(a[i],maxn);
		}
		cout<<maxn;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					maxn=max(maxn,a[i]&a[j]);
				}
			}
		}
		cout<<maxn;
	}else if(m==n){
		cout<<v[n];
	}else{
		for(int i=1;i<=n;i++){
			b[1]=a[i];
			f(i+1,m-1,a[i]);
		}
		cout<<maxn;
	}
	return 0;
}
