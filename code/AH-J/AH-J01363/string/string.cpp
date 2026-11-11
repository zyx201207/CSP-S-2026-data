#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,Mod=998244353;
int a[N];
char c[N];
void solve(){
	int n;
	cin>>n;
	int ss=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ss+=a[i];
	}
	int j=n,qwq=0,ans=0;
	for(int i=1;i<=n;i++){
		int s=0;
		qwq+=a[i];
		if(qwq>ss/2){
			while(j>i){
				if(c[j]!=c[i])
					ans+=a[j];
				j--;	
			}
			break;
		}
		while(s+a[j]<=a[i]){
			s+=a[j];
			if(c[i]!=c[j])
				ans+=a[j];
			j--;
		} 
		if(s<=a[i]){
			a[j]-=(a[i]-s);
			if(c[i]!=c[j])
				ans+=(a[i]-s); 
		}
	}
	cout<<ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t=1;
	while(t--)
		solve();
	return 0;
}
