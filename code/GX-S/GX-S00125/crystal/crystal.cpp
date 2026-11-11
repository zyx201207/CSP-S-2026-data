#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010]={};
long long s[500010]={};
int ans=-999999;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int gans;
		for(int j=1;j<=i-1;j++){
			int cc=(i-j)*a[i]-(s[i-1]-s[j-1]);
			if(cc<=m){
				gans=i-j+1;
				break;
			}
		}
		ans=max(gans,ans);	
    }
    cout<<ans;
}
