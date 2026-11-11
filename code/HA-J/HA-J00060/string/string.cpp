#include <bits/stdc++.h>
using namespace std;
#define int long long 
struct node{
	int num;
	char ch;
}a[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].ch;
		ans+=a[i].num;
	}
	int l=1,r=n,ln=0,rn=ans,daan=0;
	int xzl,xzr;
	char fl=a[l].ch,fr=a[r].ch;
	xzl=a[l].num;
	xzr=a[r].num;
	while(l<r){
		if(xzl>xzr){
			if(fl!=fr)daan+=xzr;
			rn-=xzr;
			xzl-=xzr;
			r--;
			xzr=a[r].num;
			fr=a[r].ch;
		}else if(xzl<xzr){
			if(fl!=fr)daan+=xzl;
			ln+=xzl;
			xzr-=xzl;
			l++;
			xzl=a[l].num;
			fl=a[l].ch;
		}else if(xzl==xzr){
			if(fl!=fr)daan+=xzl;
			l++,r--;
			xzl=a[l].num;
			xzr=a[r].num;
			fl=a[l].ch;
			fr=a[r].ch;
		}
	}
	cout<<daan;
	return 0;
}


