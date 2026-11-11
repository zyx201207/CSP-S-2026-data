#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int n,m;
long long ans,ma,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++)ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++)ma=max(ma,a[i]);
		cout<<ma;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			ans=a[i];
			for(int j=i+1;j<=n;j++){
				if(i!=j){
					long long x=ans&a[j];
					ma=max(ma,x);
				}
			}
		}
		cout<<ma;
		return 0;
	}
	do{
		ans=a[1];
		for(int i=2;i<=m;i++)ans=ans&a[i];
		ma=max(ma,ans);
	}while(next_permutation(a+1,a+n+1));
	cout<<ma;
	return 0;
}
