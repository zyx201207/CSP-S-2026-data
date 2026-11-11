#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, a[200005], ans=0;
char c[200005];
void solve(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i]>>c[i];
	}
	c[0]=c[n+1]=' ';
	int l=0, r=n+1, ls=0, rs=0;
	while(l<=r){
		if(l+1==r){
			break;
		}else{
			while(ls<=rs&&l+1<r){
				l++;
				ls+=a[l];
				if(c[l]!=c[r]&&r!=n+1){
					if(ls<=rs)ans+=a[l];
					else ans+=rs-(ls-a[l]);
				}
//				cout<<"ls:"<<ls<<" "<<"rs:"<<rs<<" "<<"ans:"<<ans<<'\n';
//				cout<<"L:"<<l<<' '<<r<<'\n'; 
			}
			while(rs<=ls&&r-1>l){
				r--;
				rs+=a[r];
				if(c[r]!=c[l]&&l!=0){
					if(rs<=ls)ans+=a[r];
					else ans+=ls-(rs-a[r]);
				}
//				cout<<"ls:"<<ls<<" "<<"rs:"<<rs<<" "<<"ans:"<<ans<<'\n';
//				cout<<"R:"<<l<<' '<<r<<'\n';
			}
		}
	}
	cout<<ans;
}
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
}
/*
想上迷惑行为大赏(luogu:1451514)
估分：100+100+100+48
下面的是用来骗你进来的 
freopen("ans.in", "r", stdin)
freopen("srting.in", "r", stdin)
freopen("traval.in", "r", stdin)
freopen("crad.in", "r", stdin)
freopen(".in", "r", stdin)
froopen(".in", "r", stdin)
feropen(".in", "r", stdin)
frepoen(".in", "r", stdin)
*/
