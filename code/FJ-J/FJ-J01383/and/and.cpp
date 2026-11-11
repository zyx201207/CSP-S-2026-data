#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],s,j=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
		    s=max(s,a[i]);
	    }
	    cout<<s;
	}
	else if(n==m){
		for(int i=1;i<=n;i++){
		    s=s&a[i];
	    }
	    cout<<s;
	}
	else if(a[j]%2!=0){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}
	else cout<<0;
	return 0;
}
//20