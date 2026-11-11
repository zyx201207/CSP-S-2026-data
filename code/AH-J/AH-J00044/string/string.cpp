#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n;
struct node{
	ll cnt;
	char ch;
}a[200005];
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].ch;
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l].cnt<a[r].cnt){
			if(a[l].ch!=a[r].ch){
				ans+=a[l].cnt;
			}
			a[r].cnt-=a[l].cnt;
			l++;
		}else if(a[l].cnt>a[r].cnt){
			if(a[l].ch!=a[r].ch){
				ans+=a[r].cnt;
			}
			a[l].cnt-=a[r].cnt;
			r--;
		}else{
			if(a[l].ch!=a[r].ch){
				ans+=a[r].cnt;
			}
			a[l].cnt=a[r].cnt=0;
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
