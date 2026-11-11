#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n;
ll m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	if(n<=5000){
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ll t=m;
		int tans=1;
		for(int j=i-1;j>0;j--)
			if((a[i]-a[j])<=t){
				tans++;
				t-=a[i]-a[j];
			}else break;
		ans=max(ans,tans);
	}
	}
	else{
		ll cnt=m/(a[1]-a[0]);
		ll num=(int(sqrt(8*cnt+1))-1)/2;
		ans=num+1;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
