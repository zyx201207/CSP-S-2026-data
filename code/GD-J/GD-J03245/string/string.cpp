#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define int long long
int n;
struct s{
	int x;
	char c;
	//int l,r;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int t=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		t+=a[i].x;
		//a[i].l=a[i-1].r+1;
		//a[i].r=a[i].l+a[i].x-1;
	}
	int l=1,r=n,ans=0;
	while(l<r){
		int v=min(a[l].x,a[r].x);
		if(a[l].c!=a[r].c){
			ans+=v;
		}
		a[l].x-=v;
		a[r].x-=v;
		if(a[l].x==0){
			l++;
		}
		if(a[r].x==0){
			r--;
		}
	}
	cout<<ans;
	return 0;
}
