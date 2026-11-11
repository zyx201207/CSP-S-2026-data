#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx,a[200100],ma,as,flag=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
		as=as&a[i];
		if(a[i]<a[i-1]) flag=1;
	}
	if(flag==0){
		cout<<n-m;
		return 0;
	}
	if(m==n){
		cout<<as;
	    return 0;
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	sort(a+1,a+n+1);
	ma=0;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);		
			}
		}
		cout<<ma;
		return 0;
	}
	cout<<a[n-m+1];
	return 0;
}

