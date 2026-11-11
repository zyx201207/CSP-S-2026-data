#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m,a[500005],d[500005],ans;
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
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		ll w=0,num=1;
		for(int j=i+1;j<=n;j++){
			w+=num*d[j];
			if(w>m||num+n-j+1<=ans) break;
			num++;
		}
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}
