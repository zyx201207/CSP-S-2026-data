#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],ans=1,cnt=1,h;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		h+=cnt*(a[i]-a[i-1]);
		cnt++;
		while(h>m){
			h-=a[i]-a[i-cnt+1];
			cnt--;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
