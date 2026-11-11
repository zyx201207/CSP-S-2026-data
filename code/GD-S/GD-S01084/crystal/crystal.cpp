#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,a[N],m,cnt,ans,cnt1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=1;
	cnt=0;
	cnt1=1;
	for(int i=2;i<=n;i++){
		cnt+=(a[i]-a[i-1])*cnt1; 
		while(cnt>m){
			cnt-=a[i]-a[i-cnt1];
			cnt1--;
		}
		cnt1++;
		ans=max(ans,cnt1);
	}
	cout<<ans;
}
