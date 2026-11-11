//GZ-J00485 ³Â×ÓÐù
#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,o=0;
long long a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<a[0];
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(o<a[i]){
			o=a[i];
		}
	}
	if(m==1){
		cout<<o;
		return 0;
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j){
					if(a[i]&a[j]>ans){
						ans=a[i]&a[j];
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(n<=2000){
	if(m==3){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int z=0;z<n;z++){
				if(i!=j&&i!=z&&j!=z){
					if(a[i]&a[j]&a[z]>ans){
						ans=a[i]&a[j]&a[z];
					}
				}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	}
	if(m==n-1){
		for(int i=0;i<n;i++){
			int ui;
			if(i==0) ui=a[1];
			else ui=a[0]; 
			for(int j=0;j<n;j++){
				if(i!=j){
					ui&=a[j];
				}
			}
			if(ans<ui){
				ans=ui;
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		sort(a,a+n,greater<int>());
		ans=a[0];
		for(int i=1;i<n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}
