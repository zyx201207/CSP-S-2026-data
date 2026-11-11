#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++) mx=max(mx,a[i]);
		cout<<mx;
	}else if(m==2){
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
	}else if(m==n){
		sum=a[1];
		for(int i=2;i<=n;i++) sum&=a[i];
		cout<<sum;
	}else if(m==n-1){
		cout<<2147483648;
	}
	return 0;
}
