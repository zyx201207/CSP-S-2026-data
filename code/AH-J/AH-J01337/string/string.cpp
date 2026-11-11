#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n;
struct node{
	int num;char c;
}a[200005];
int l,r,ans;
int luse,ruse;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	l=1,r=n;
	luse=a[1].num,ruse=a[n].num;
	while(l<r){
		int mn=min(luse,ruse);
		if(a[l].c==a[r].c){
			luse-=mn,ruse-=mn;
		}
		else{
			ans+=mn;
			luse-=mn,ruse-=mn;
		}
		if(luse==0)l++,luse=a[l].num;
		if(ruse==0)r--,ruse=a[r].num;
	}
	cout<<ans<<endl;
	return 0;
}
