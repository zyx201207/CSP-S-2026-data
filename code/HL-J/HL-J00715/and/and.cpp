#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans=-1e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i] & a[j]));
			}
		}
		cout<<ans;
	}else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					ans=max(ans,(a[i] & a[j] & a[k]));
				}
			}
		}
		cout<<ans;
	}else cout<<0;
	return 0;
}