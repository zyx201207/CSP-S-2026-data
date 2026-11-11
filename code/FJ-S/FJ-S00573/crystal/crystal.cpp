#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,m,t,ans,a[514514];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n>5000){
		int mubiao=m/(a[2]-a[1]);
		int sqt=sqrt(mubiao*2);
		if(sqt*(sqt+1)/2<=mubiao) cout<<sqt+1;
		else cout<<sqt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long s=0,t=1;
		for(int j=i-1;j>=1;j--,t++){
			s+=a[i]-a[j];
			if(s>m) break;
		}
		ans=max(ans,t);
	}
	cout<<ans;
	return 0;
}
