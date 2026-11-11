#include<bits/stdc++.h>//Trick||Treat!
#define int long long 
using namespace std;
struct nd {
	int num;
	string kind;
} a[1000005];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,gn=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i].num>>a[i].kind;
		gn+=a[i].num;
	}


	int ln=0,mpos=0,ans=0;
	for(int i=1; i<=n; i++) {
		ln+=a[i].num;
		if(ln>=gn/2+(gn%2==1)) {
			if(gn%2==1){
				a[i].num-=1;
				gn-=1;
				ln-=1;
			}
			if(a[i].num-(ln-gn/2)<=ln-gn/2)mpos=i-1;
			else mpos=i;
			a[i].num=abs(a[i].num-(ln-gn/2)-(ln-gn/2));
			break;
		}
	}
	int l=mpos,r=mpos+1;
	while(l>0) {
		if(a[l].num>a[r].num) {
			a[l].num-=a[r].num;
			ans+=a[r].num*(a[l].kind!=a[r].kind);
			a[r].num=0;
			r++;
		}
		if(a[l].num==a[r].num) {
			ans+=a[l].num*(a[l].kind!=a[r].kind);
			a[l].num=0,a[r].num=0;
			l--,r++;
		}
		if(a[r].num>a[l].num) {
			a[r].num-=a[l].num;
			ans+=a[l].num*(a[l].kind!=a[r].kind);
			a[l].num=0;
			l--;
		}
	}
	cout<<ans;
	return 0;
}
