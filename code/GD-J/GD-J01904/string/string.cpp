#include<bits/stdc++.h>
#define int long long
using namespace std;
struct loj{
	int x;
	char ch;
}a[200010],b[200010];
int n,ans,cnt,s[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) {
		int x;
		char ch;
		cin>>x>>ch;
		if(ch==a[cnt].ch) {
			a[cnt].x+=x;
		}
		else {
			a[++cnt]={x,ch};
		}
	}
	n=cnt;
	int l=1,r=n;
	while(l<r){
		if(a[l].ch==a[r].ch){
			int k=min(a[l].x,a[r].x);
			a[l].x-=k;
			a[r].x-=k;
			if(a[l].x==0)l++;
			if(a[r].x==0)r--;
		}
		else if(a[l].ch!=a[r].ch){
			if(a[r].x>a[l].x){
				a[r].x-=a[l].x;
				ans+=a[l].x;
				l++;
			}
			else if(a[r].x<a[l].x){
				a[l].x-=a[r].x;
				ans+=a[r].x;
				r--;
			}
			else{
				ans+=a[l].x;
				l++,r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
