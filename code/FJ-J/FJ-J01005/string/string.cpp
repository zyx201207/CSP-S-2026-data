#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;

int n,s,ans;

struct node{
	int num;
	char c;
}a[N];

void solve(){
	cin>>n;
	s=0;
	for(int i=1;i<=n;i++)cin>>a[i].num>>a[i].c;
	for(int i=1;i<=n;i++)s+=a[i].num;
	s/=2;
	int now=0,noww=0,p=n,cnt=0;
	char x;
	for(int i=1;i<=n;i++){
		noww+=a[i].num;
		x=a[i].c;
		if(noww>s) noww=s;
		if(noww<=s){
			for(int j=p;j>=1;j--){
				if(a[j].c!=x) ans+=a[j].num-now;
				cnt+=a[j].num-now;
				p=j;
				if(cnt>=noww){
					if(a[j].c!=x) ans-=cnt-noww;
					now=a[j].num-(cnt-noww);
					cnt=noww;
					break;
				}
				now=0;
			}
		}
	}
	cout<<ans;
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0);
	int TTT=1;
//	cin>>TTT;
	while(TTT--){
		solve();
	}
}