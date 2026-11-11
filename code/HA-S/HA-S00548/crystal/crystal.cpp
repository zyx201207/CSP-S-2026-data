#include<bits/stdc++.h>
using namespace std;
long long int l,n,m,ans,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	l=m;
	for(int i=n;i>=1;i--){
		l-=a[n]-a[i-1];
		if(l>=0){
			ans++;
		}else {
			l+=a[n]-a[i-1];
			break;	
		}
	}
	m=l;
	ans++;
	for(int i=n;i>ans+1;i--){
		l+=(ans-1)*(a[i]-a[i-1])-a[i-1]+a[i-ans];
			for(int j=1;j>=0;j){
				if(l>=a[i-1]-a[i-1-ans]){
				ans++;
				l-=a[i-1]-a[i-ans];
				
				}else break;
			}
	}cout<<ans;
	//5 8 -3 -1 2 2 7
	return 0;
}
