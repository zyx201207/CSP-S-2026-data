#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct node{int w;char ch;};
node a[N];
int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++) cin>>a[i].w>>a[i].ch;
	int l=1,r=n;
	while(l<=r){
		if(a[l].ch==a[r].ch){
			if(a[l].w<a[r].w){
				a[r].w-=a[l].w;
				l++;
			}
			else if(a[l].w==a[r].w) l++,r--;
			else if(a[l].w>a[r].w){
				a[l].w-=a[r].w;
				r--;
			}
		}
		else{
			if(a[l].w<a[r].w){
				ans+=a[l].w;
				a[r].w-=a[l].w;
				l++;
			}
			else if(a[l].w==a[r].w) ans+=a[l].w,l++,r--;
			else if(a[l].w>a[r].w){
				ans+=a[r].w;
				a[l].w-=a[r].w;
				r--;
			}	
		}
	}
	cout<<ans;
	return 0;
}
