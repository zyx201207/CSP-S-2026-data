#include<bits/stdc++.h>
using namespace std;




int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=a[1];
	if(m==n){
		for(int i=1;i<=n;i++){ans=(a[i] & ans);
		}
	}
	else if(m==1){
			ans= a[n];	
	}
	else if(m==n-1){ans=a[2];
		for(int i=2;i<=n;i++){ans=(a[i] & ans);
		}
	}
	else {ans=a[n];
		for(int i=n-m+1;i<=n;i++){ans=(a[i] & ans);
	}
	
	
	
	
	cout<<ans;
	
	
	
	
	return 0;} 
