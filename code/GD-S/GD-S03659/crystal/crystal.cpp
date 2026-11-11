#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
int pre[N];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)flag=0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		if((a[i]*i-pre[i])>m){
			ans=i-1;
			break;
		}
	}
	int h=1,t=ans,sl=t-h+1;
	while(h<=t&&t<n){
		h++;
		sl--;
		int tmp=sl;
		for(int i=t+1;i<=n;i++){
			tmp++;
			int v=(a[i]*tmp-(pre[i]-pre[h-1]));
			if(v>m){
				ans=max(ans,sl);
				break;
			}
			else{
				t++;
				sl++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
