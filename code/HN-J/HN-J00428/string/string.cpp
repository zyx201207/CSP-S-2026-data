#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5+25;
struct node{
	int len;
	char c;
}a[N];
int n,ans;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int len;
		char c;
		cin>>len>>c;
		if(c==a[i-1].c){
			a[i-1].len+=len;
			i--;
			n--;
		}
		else{
			a[i].len=len;
			a[i].c=c;
		}
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].c!=a[r].c){
			if(a[l].len==a[r].len){
				ans+=a[l].len;
				l++;
				r--;
			}
			else if(a[l].len<a[r].len){
				ans+=a[l].len;
				a[r].len-=a[l].len;
				l++;
			}
			else{
				ans+=a[r].len;
				a[l].len-=a[r].len;
				r--;
			}
		}
		else{
			if(a[l].len==a[r].len){
				l++;
				r--;
			}
			else if(a[l].len<a[r].len){
				a[r].len-=a[l].len;
				l++;
			}
			else{
				a[l].len-=a[r].len;
				r--;
			}
		}
	}
	cout<<ans;
	return ;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
} 
