#include<bits/stdc++.h>
using namespace std;
const int N=5e5+6;
long long n,m,a[N],ans=0;
int b=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) b=0;
	}
	if(b==1){
		int c=a[2]-a[1];
		long long d=2*m/c;
		for(int i=1;i*(i-1)<=d;i++) ans=i;
		cout<<min(n,ans);
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=n;i>ans;i--){
		long long mm=m,ansm=0;
		for(int j=i-1;mm-a[i]+a[j]>=0;j--){
			ansm++;
			mm-=(a[i]-a[j]);
		}
		if(ansm>ans) ans=ansm;
	}
	cout<<ans+1;
	return 0;
}
