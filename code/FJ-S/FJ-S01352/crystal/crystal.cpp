#include<bits/stdc++.h>
using namespace std;
long long m,n,a[600000],s[600000],ans;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){

		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	a[0]=0;
	s[0]=0;
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	for(long long i=n;i>=1;i--){
				
		for(long long j=1;j<i;j++){
					                                                        
			if(s[i]-s[j-1]+m>=a[i]*i){
				ans=max(ans,i-j+1);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
