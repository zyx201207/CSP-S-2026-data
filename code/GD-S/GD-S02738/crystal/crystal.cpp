#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
long long a[500005],f[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		 cin>>a[i]; 
	}
	sort(a+1,a+1+n);
	for(int i=2;i<n;i++){
		f[i]=0;
		for(int j=i-1;j>=1;j--){
			f[j]=a[i]-a[j];
			f[i]+=f[j];
			if(f[i]>m){
				break;
			}
			ans=max(ans,i-j+1);
		}
	}
	cout<<ans;
}
