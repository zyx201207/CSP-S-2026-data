#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,ans=0;
struct node{
	ll x;
	char ch;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].ch;
	for(int i=1,j=n;i<=j;i++){
		ll tmp=a[i].x,cnt=0;
		for(;j>=i&&tmp>0;j--){
			if(a[j].x>tmp){
				cnt+=(a[j].ch!=a[i].ch)?tmp:0;
				a[j].x-=tmp;
				tmp=0;break;
			}
			else{
				cnt+=(a[j].ch!=a[i].ch)?a[j].x:0;
				tmp-=a[j].x;
			}
		}
		//cout<<i<<" "<<j<<" "<<cnt<<"\n"; 
		ans+=cnt;
	}
	cout<<ans;
	return 0;
}
/*3
2 a 1 c 1 b 1 d*/
