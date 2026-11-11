#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
bool cmp(int a,int b){
		return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long mx=0;
	if(n<=2000&&m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>mx) mx=a[i];
		}
	}else if(n<=2000&&m==n){
		mx=a[1];
		for(int i=2;i<=n;i++){
			mx&=a[i];
		}
	}else if(n<=2000&&m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>mx) mx=a[i]&a[j];
			}
		}
	}
	else if(m==n-1){
		mx=a[2];
		for(int j=3;j<=n;j++){
			mx&=a[j];
		}
		for(int i=2;i<=n;i++){
			long long mxn=a[1];
			for(int j=2;j<=n;j++){
				if(j!=i){
					mxn&=a[j];
				}
			}
			if(mxn>mx) mx=mxn;
		}
	}else{
		sort(a+1,a+n+1,cmp);
		mx=a[m];
	}	
	cout<<mx;
	return 0;
}
