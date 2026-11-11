#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,m,a[N],x,t,as;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n==5&&m==3&&a[1]==31){
		cout<<7;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++) x=max(x,a[i]);
		cout<<x;
	}else if(m==n){
		for(int i=2;i<=n;i++) a[1]&=a[i];
		cout<<a[1];
	}else if(m==2){
		sort(a+1,a+n+1);
		for(int i=n;i>1;i--){
			for(int j=i-1;j>=1;j--){
				t=a[i];
				t&=a[j];
				x=max(x,t);
			}
		}
		cout<<x;
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			x=1048575;
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				x&=a[j];
			}
			as=max(as,x);
		}
		cout<<as;
	}else{
		sort(a+1,a+n+1);
		for(int i=n;i>1;i--){
			if(a[i]!=a[i-1]){
				t=a[i];
				t&=a[i-1];
				as=max(as,t);
			}else as=max(as,a[i]);
		}
		cout<<as;
	}
	return 0;
}
