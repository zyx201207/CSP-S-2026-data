#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,a[500010],ml;
int n,cnt=1,ans=1;
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++){
		ml+=(a[i]-a[i-1])*cnt;
		if(m<ml){
			while(m<ml){
				cnt--;
				ml-=a[i]-a[i-cnt];
			}
		}
		cnt++;
		ans=max(ans,cnt);
	}
	cout<<ans;
	
	return 0;
}