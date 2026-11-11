#include <bits/stdc++.h>
using namespace std;
int n,m,ans,ans2;
int a[200005];
bool m1=false,m2=false,mn=false;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		m1=true;
	}else if(m==2){
		m2=true;
	}else if(m==n){
		mn=true;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(m1){
			if(a[i]>ans){
				ans=a[i];
			}
		}
		else if(m2){
			if(a[i]>ans){
				ans=a[i];
			}else{
				if(a[i]>ans2){
					ans2=a[i];
				}
			}
		}
		else if(mn){
			if(i==0){
				ans=a[i];
			}else{
				ans=ans&a[i];
			}
		}
	}
	if(m1){
		cout<<ans;
	}else if(mn){
		cout<<ans;
	}else if(m2){
		ans=ans&ans2;
		cout<<ans;
	}else{
		sort(a,a+n,cmp);
		ans=a[0];
		for(int i=1;i<m;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	return 0;
}
