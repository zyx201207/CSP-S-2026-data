#include<bits/stdc++.h>
using namespace std;
#define ll long long 
struct node{
	ll s;
	char id;
}a[200005];
int n,m;
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].s>>a[i].id;
	int l=1,r=n;
	while(l<r){
		int t=min(a[l].s,a[r].s);
		if(a[l].id!=a[r].id) ans+=t;
		a[l].s-=t,a[r].s-=t;
		if(a[l].s==0) l++;
		if(a[r].s==0) r--;
	}
	cout<<ans;
	return 0;
} 
