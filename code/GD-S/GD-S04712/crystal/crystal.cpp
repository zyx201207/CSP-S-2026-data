#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull; 
const int N=5e5+5;

ull n,m;
ll a[N];
ll qe[N];
ll hd=1,v,cnt=1,ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//freopen("crystal4.in","r",stdin);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);

	for(int i=2;i<=n;i++){
		v+=(a[i]-a[i-1])*cnt;
		cnt++;
		while(v>m){
			cnt--;
			v-=a[i]-a[i-cnt];
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	
	
	return 0;
	
	
}
