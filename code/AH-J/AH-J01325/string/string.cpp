#include<bits/stdc++.h>
using namespace std;
struct o{
	char c;
	int x;
}a[200005];
int n,l,r,lc,rc;
long long ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].c;
	l=1,r=n;
	while(l<r){
		int x=min(a[l].x,a[r].x);
		if(a[l].c!=a[r].c)ans+=x;
		if(a[l].x==x)l++;
		else a[l].x-=x;
		if(a[r].x==x)r--;
		else a[r].x-=x;
	}
	cout<<ans;
	return 0;
}
