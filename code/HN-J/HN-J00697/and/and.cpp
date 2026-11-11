#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[2222];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx=-1e9;
	if(m==2){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((a[i]&a[j])>maxx){
				maxx=(a[i]&a[j]);
			}
		}
		} 
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			maxx&=a[i];
		}
	}
	cout<<maxx;
}
