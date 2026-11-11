#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1)	
		for(int i=1;i<=n;i++)
			ans=max(ans,a[i]);
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
	}
	cout<<ans;
	return 0;
}
