#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],ans;
int main(){
	cin>>n>>m;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>ans)ans=a[i];
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				if(a[i]&a[j]>ans)ans=i&j;
			}
		}
		}
	}
	else{
		cin>>a[1];
		ans=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
}
