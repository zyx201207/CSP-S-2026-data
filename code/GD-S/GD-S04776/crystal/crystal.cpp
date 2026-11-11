#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int asd(int n,int m,int x){
	int s;
	if(m==0){
		return x;
	}
	for(int i=1;i<=n;n++){
		for(int j;j<=n;j++){
			if(a[i]-a[j]==1){
				a[j]+=1;
				asd(n,m-1,x+1);
				a[j]-=1;
			}
			if(a[j]-a[i]==1){
				a[i]+=1;
				asd(n,m-1,x+1);
				a[i]-=1;
			}
		}
	}
}
int main() {
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	long long n,m,x=0;
	cin>>n>>m;
	long long b[n+1][n+1];
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
    cout<<asd(n,m,x);
	return 0;
}


