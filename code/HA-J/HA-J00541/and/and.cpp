#include<bits/stdc++.h>
using namespace std;
long long n,m,a[210000],ans=-10000,s;
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					s=a[i]&a[j];
					ans=max(ans,s);
				}
			}
		}
		cout<<ans;
		return 0;	
	}
	return 0;
}
