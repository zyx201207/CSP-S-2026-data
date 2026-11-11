#include<bits/stdc++.h>
using namespace std;
struct str{long long x;char c;}a[200010];
int n;long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].c;
	int l=1,r=n;
	while(l<r){
		if(a[l].c==a[r].c){long long tmp=min(a[l].x,a[r].x);a[l].x-=tmp;a[r].x-=tmp;}
		else{
			ans+=min(a[l].x,a[r].x);long long tmp=min(a[l].x,a[r].x);a[l].x-=tmp;a[r].x-=tmp;
		}
		if(a[l].x==0)l++;
		if(a[r].x==0)r--;
	}
	cout<<ans;
	return 0;
}
/*
676767676767676767676767
weishenme meici douzai zhezhong shihou kao csp
wodou meishijian fuxi qizhongkao
bushi zuijin de csp weishenme zhemeshui
*/
