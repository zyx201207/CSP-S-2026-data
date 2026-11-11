#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],c[N],ans,sum,L=1,R=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	while(R<n){
		int ss=(R-L+1)*(a[R+1]-a[R]);
		if(sum+ss<=m){
			sum+=ss;
			R++;
			ans=max(ans,R-L+1);
			continue;
		}
		else{
			if(R==L){
				R++;
				L++;
			}
			else{
				int ss2=a[R]-a[L];
				sum-=ss2;
				L++;
			}
		}
	}
	cout<<ans;
	return 0;
}
