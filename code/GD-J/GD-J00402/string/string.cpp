#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x;
	char y;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
//	scanf("%d",&n);
	for(int i=1; i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	int l=1,r=n,ans=0;
	while(l<r){
//		cout<<l<<" "<<r<<endl;
		int mi=min(a[l].x,a[r].x);
		if(a[l].y!=a[r].y){
			ans+=mi;
		}
		a[l].x-=mi;
		a[r].x-=mi;
		if(!a[l].x) l++;
		if(!a[r].x) r--;
	}
	cout<<ans;
	return 0;
}
