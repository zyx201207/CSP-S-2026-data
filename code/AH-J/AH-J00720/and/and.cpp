#include <bits/stdc++.h>
using namespace std;
long long n,m,x,a[2000020],maxa=-1;
long long b=pow(2,31)-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a,a+n+1);
		cout<<a[n];
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]&=a[j]>=maxa)
				maxa=a[i]&=a[j];
			
		}
		cout<<maxa;
	}
}
	else if(m==n){
		for(int i=1;i<=n;i++){
			b&=a[i];
		}
		cout<<b;
	}else{
	cout<<0;	
	}
	return 0;
}
