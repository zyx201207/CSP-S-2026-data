#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long n,m;
long long a[MAXN];
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	long long maxx=INT_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	} 
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==2){
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		} 
		cout<<ans;
		return 0;
	} 
	return 0;
}

