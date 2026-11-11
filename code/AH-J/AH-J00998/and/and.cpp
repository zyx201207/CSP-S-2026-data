#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],v,t;
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) v=a[i]; 
		v&=a[i];
	}
	sort(a+1,a+n+1);
	if(m==1) cout<<a[n];
	else if(m==n) cout<<v;
	else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i;j<=n;j++) t=max(t,(a[i]&a[j]));
		}
		cout<<t;
	}
	else{
		t=a[n];
		for(int i=n-1;i>n-m;i--) t&=a[i];
		cout<<t;
	}
	return 0;
}
