#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
char c[N];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,li=n,sy=a[1];
	int ans=0;
	while(i<li){
		while(sy!=0){
			if(sy>=a[li]){
				sy-=a[li];
				if(c[i]!=c[li]){
					ans+=a[li];
				}
				a[li]=0;
				li--;
			}else{
				a[li]-=sy;
				if(c[i]!=c[li]){
					ans+=sy;
				}
				sy=0;
			}
		}
		i++;
		sy=a[i];
	}
	cout<<ans;
	return;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;
	while(T--)solve();
	return 0;
}
