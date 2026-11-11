#include <bits/stdc++.h>
using namespace std;
int a[100001];
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;cin>>n;int m;cin>>m;
	int k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) k=a[i];
		else k=a[i]&k;
	}
	sort(a+1,a+n+1,cmp);
	if(n<=20000){
		if(m==1){
			 cout<<a[n];
			 return 0;
		}
		if(m==2){
			int ans=0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans;
			return 0;
		}
		if(m==n){
			cout<<k;
			return 0;
		}
	}
	if(n<=200000){
		bool f=1;
		for(int i=1;i<=n/10;i++)
		if((a[i]^0)!=a[i]) f=0;
		if(f==1) cout<<a[m];
		return 0;
	}
}
