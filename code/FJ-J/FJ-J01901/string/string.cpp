#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200001],i=1,j,m=0,ans=0,t;
string b[200001];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	j=n;
	for(int i1=1;i1<=n;i1++){
		cin>>a[i1]>>b[i1];
	}
	while(i<j){
		m=min(a[i],a[j]);
		if(b[i]!=b[j]){
			ans+=m;
		}
		a[i]-=m;a[j]-=m;
		if(a[i]==0) i++;
		if(a[j]==0) j--;
	}
	cout<<ans;
	return 0;
}
