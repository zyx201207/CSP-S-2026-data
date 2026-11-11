#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+50;
ll n,ans,f[maxn];
char w[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>f[i]>>w[i];
	int l=1,r=n;
	while(l<r){
		if(f[l]>f[r]){
			if(w[l]!=w[r]) ans+=f[r];
			f[l]-=f[r],f[r]=0,r--;
		}
		if(f[l]<=f[r]){
			if(w[l]!=w[r]) ans+=f[l];
			f[r]-=f[l],f[l]=0,l++;
		}
	}
	cout<<ans;
	return 0;
}
