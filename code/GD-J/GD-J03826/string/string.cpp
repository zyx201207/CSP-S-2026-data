#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct block{
	char c;
	int sum;
}a[N];
int n,tot,acnt,ans;
bool vis[30];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].sum >> a[i].c;
		tot+=a[i].sum;  
		int u=a[i].c-'a';
		if(!vis[u]) vis[u]=1,acnt++;
	}
	if(acnt==1){
		cout << 0;
		return 0;
	}
	if(a[1].sum>tot/2){
		cout << tot-a[1].sum;
		return 0;
	}
	int i=1,j=n,lcnt=0,rcnt=0,ls=a[1].sum,rs=a[n].sum;
	char lc=a[1].c,rc=a[n].c;
	while(1){
		if(ls==rs){
			if(rc==lc) i++,j--;
			else ans+=ls,i++,j--;
			ls=a[i].sum,rs=a[j].sum,lc=a[i].c,rc=a[j].c;
		}else if(ls<rs){
			if(lc!=rc) ans+=ls;
			rs-=ls,i++,ls=a[i].sum,lc=a[i].c;
		}else if(ls>rs){
			if(lc!=rc) ans+=rs;
			ls-=rs,j--,rs=a[j].sum,rc=a[j].c;
		}
		if(i==j) break;
	}
	cout << ans;
	return 0;
}
