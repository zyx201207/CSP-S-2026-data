#include<bits/stdc++.h>
using namespace std;

long long maxx=0,n,a[100010],b[100010];
long long m;
int jg(long long a[100010],int djg,long long m){
	int ii=0;
	for(int i=djg;i>=1;i--){
		if(m>=a[djg]-a[i]){
			m-=(a[djg]-a[i]);
			ii=djg-i+1;
		}
	}
	return ii;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(maxx<jg(a,i,m)){
			maxx=jg(a,i,m);
		}
	}
	cout<<maxx;
	return 0;
}
