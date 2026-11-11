#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5;
int n,ans=0;
struct String{
	int a;
	char c;
}str[N+5];
void solve(){
	int l=1,r=n;
	while(l<=r){
		if(str[l].c!=str[r].c){
			if(str[l].a<=str[r].a){
				str[l].c=str[r].c;
				ans+=str[l].a;
				str[r].a-=str[l].a;
				l++;
			}
			else{
				str[r].c=str[l].c;
				ans+=str[r].a;
				str[l].a-=str[r].a;
				r--;
			}
		}
		else{
			if(str[l].a<=str[r].a) str[r].a-=str[l++].a;
			else str[l].a-=str[r--].a;
		}
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>str[i].a>>str[i].c;
	solve();
	cout<<ans;
	return 0;
}
