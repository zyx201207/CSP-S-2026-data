#include<bits/stdc++.h>
using namespace std;
int n,m,o;
int a[20005],h,ans;
bool u(int x,int y){
	if(x<y) swap(x,y);
	if(x%y!=0) return false;
	if(x%y==0){
		x/=y;
		while(x=0){
		    if(x%2!=0) return false;
		    x/=2;
	    }
	}
	return true;	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		o=max(o,a[i]);
	}
	if(m==1){
		cout<<o;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int l=i+1;l<=n;l++){
				if(u(a[i],a[l])==false){
					ans=max(ans,min(a[i],a[l]));
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
3/2 1
12/2*/
