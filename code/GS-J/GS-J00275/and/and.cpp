#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],cnt,mxn;

int main(){
  	freopen("and.in","r",stdin);
  	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=m;i++){
			mxn=max(mxn,a[i]);
		}
		cout<<mxn;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				
				mxn=max(mxn,a[i]&a[j]);
				
			}
		}	
		cout<<mxn;
		return 0;
	}
	sort(a+1,a+n+1);
	if(m<n){
		mxn=a[n];
		for(int i=n-1;i>n-m;i--){
			mxn&=a[i];
		}	
		cout<<mxn;
		return 0;
	}
	
	;
	if(m==n){
		for(int i=1;i<=m;i++){
			cnt&=a[i];	
		}
		cout<<cnt;
		return 0;
	}
	cout<<cnt;
	return 0;
}
