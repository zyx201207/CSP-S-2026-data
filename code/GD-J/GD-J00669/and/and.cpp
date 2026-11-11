#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=-1,maxx=-1;
bool cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
	    cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
	}else if(m==2){
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else if(m==n){
		for (int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}else if(m==n-1){
		int mx=-1;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if(i!=j) mx=mx&a[j];
			}
			ans=max(ans,mx);
		}
		cout<<ans;
	}else{
		sort(a+1,a+1+n,cmp);
		for (int i=1;i<=m;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
    return 0;
}
