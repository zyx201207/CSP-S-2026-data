#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100005]={};
long long z[100005]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m%2==0 and m<n){
		cout<<m/2;
	}
	else if(m%2!=0 and m<n){
		cout<<m/2+1;
	}
	else if(m==n){
		cout<<m;
	}
	return 0;
}
