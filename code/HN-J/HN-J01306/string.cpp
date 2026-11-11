#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct node{
	int num;
	char ch;
}a[N],b[N];
int n,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].ch;
	for(int i=1;i<=n;i++) b[i]=a[n-i+1];
	int i=2,j=1,cnti=a[1].num,cntj=0;
	while(i<=n||j<=n){
		while(j<=n&&cntj+b[j].num<=cnti){
			if(b[j].ch!=a[i-1].ch) ans+=b[j].num;
			cntj+=b[j].num;
			j++;
		}
		if(j<=n&&cntj<=cnti){
			if(b[j].ch!=a[i-1].ch) ans+=cnti-cntj;
			cntj+=b[j].num;
			j++;
		}
		while(i<=n&&cnti+a[i].num<=cntj){
			if(b[j-1].ch!=a[i].ch) ans+=a[i].num;
			cnti+=a[i].num;
			i++;
		}
		if(i<=n&&cnti<=cntj){
			if(b[j-1].ch!=a[i].ch) ans+=cntj-cnti;
			cnti+=a[i].num;
			i++;
		}
	}
	cout<<ans/2;
	return 0;
}

