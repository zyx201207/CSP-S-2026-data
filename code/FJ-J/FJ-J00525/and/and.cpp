#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
bool p=1;
int pd(int x) {
	int k=x+1;
	int cn=1;
	if(k==1){
		return 1;
	}
	for(int i=1;i<=20;i++){
		cn*=2;
		if(cn>k){
			return 0;
		}
		if(cn==k){
			return 1;
		}
	}
	return 0;
	 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//if(pd(a[i])==1) pd=false;
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
		ans=max(ans,a[i]);
	    }
	    cout<<ans;
	}else if(m==n){
		int ans=a[1];
		for(int i=1;i<=n;i++){
        ans=ans&a[i];
	    }
	    cout<<ans;
	}else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
		   for(int j=i+1;j<=n;j++){
		   	   ans=max(ans,a[i]&a[j]);
		   }
	    }
	    cout<<ans;
	}
	return 0;
}
