#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    int mx=-1;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	sort(a+1,a+n+1);
	if(m==2){
		int mx2=-1;
		for(int i=2;i<=n;i++){
			mx2=max(mx2,a[i]&a[i-1]);
	    }
	    cout<<mx2;
	    return 0;
    }
    if(n==m){
		int pb=a[1];
	    for(int i=2;i<=n;i++){
		    pb&=a[i];
	    }	
	    cout<<pb;
	    return 0;
	}
    int ans=a[n];
    for(int i=n-1;i>n-m;i--){
	    ans&=a[i];
	}
	cout<<ans;
    return 0;
}
