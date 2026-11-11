#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
using namespace std;

const int N=2e5+5;

int n,k,a[N];
bool fl[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	fast;
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i],fl[i]=1;
	int ans=0;
	for(int mk=31;mk>=0;--mk){
		int t=0;
		for(int i=1;i<=n;++i) t+=(bool)(a[i]&(1<<mk))&&fl[i];
		if(t>=k){
			ans+=(1<<mk);
			for(int i=1;i<=n;++i)
				if(!(a[i]&(1<<mk))) fl[i]=0;
		}
	}
	cout<<ans;
	return 0;
}

