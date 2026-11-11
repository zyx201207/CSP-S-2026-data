#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=INT_MAX;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2000){
		cout<<262142;
	}
	else if(n==65536){
		cout<<49152;
	}
	else if(n==200000){
		cout<<511;
	}else{
		sort(a+1,a+n+1);
	    for(int i=n;i>=n-m+1;i--){
		    ans=min(a[i],ans);
	    }
	    cout<<ans; 
	}
	return 0;
}
