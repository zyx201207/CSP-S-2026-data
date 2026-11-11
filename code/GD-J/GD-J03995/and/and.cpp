#include<bits/stdc++.h>
using namespace std;
long long n,m,mx;
long long a[200010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		mx=a[n];
		cout<<mx<<'\n';
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
		    for(int j=i+1;j<=n;j++){
			    if(mx<(a[i]&a[j])){
			    	mx=(a[i]&a[j]);
			    }
		    }
	    }
	    cout<<mx<<'\n';
	    return 0;
	}
	if(m==n){
		long long l=(a[1]&a[2]);
		for(int i=3;i<=n;i++){
			l=l&a[i]; 
		}
		mx=l;
		cout<<mx<<'\n';
		return 0;
	}
	return 0;
} 
