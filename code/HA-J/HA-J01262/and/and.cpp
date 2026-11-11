#include<bits/stdc++.h> 
using namespace std;
const int X=100000;
int n,m,maxx,pop;
int a[X],dp[X];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			pop=a[i]&a[j];
			if(pop>maxx)
			maxx=pop;
		}
	}
	cout<<maxx;
	return 0;
}
