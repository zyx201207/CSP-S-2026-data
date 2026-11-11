#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0;
struct node{
	int s;
	char c;
}a[200010],b[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
		b[n-i+1].s=a[i].s;
		b[n-i+1].c=a[i].c;
	}
	for(int l=1,r=1;l<=n,r<=n;){
		m=min(a[l].s,b[r].s);
		a[l].s-=m;b[r].s-=m;
		if(a[l].c!=b[r].c) ans+=m;
		if(a[l].s==0) l+=1;
		if(b[r].s==0) r+=1;
	}
	cout<<ans/2;
	return 0;
}
//9:02  100
