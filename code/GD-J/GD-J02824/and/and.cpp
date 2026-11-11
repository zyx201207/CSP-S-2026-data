#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[2000005];
int main(){
	freopen("and.in.cpp","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	long long b=a[1];
	for(int i=2;i<=n;i++){
		b=b&a[i];
	}
	long long maxm=0;
	if(m==1){
		cout<<maxn;
		return 0;
	}
	else if(m==n){
		cout<<b;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				long long c=a[i]&a[j];
				maxm=max(maxm,c);
			}
		}
		cout<<maxm;
	}
	return 0;
}
