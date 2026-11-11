#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
struct node{
	int a;
	char ch;
}s[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	ll ans = 0;
	ll cntl=0,cntr=0;
	for(int i=1; i<=n; i++){
		cin>>s[i].a>>s[i].ch;
	}
	int l;
	if(n%2==0) l = n/2;
	else l = n/2+1;
	char cl,cr;
	for(int i=1; i<=l;i++){
		int r=n-i+1;
		int x=cntl,y=cntr;
		cntl=s[i].a+cntl,cntr=s[r].a+cntr;
		if(x&&cl==s[r].ch) cntl-=x,cntr-=x;
		else if(y&&cr==s[l].ch) cntl-=y,cntr-=y;
		if(i==r){
			ans+=min(x,s[i].a);
			ans+=min(y,s[i].a);
			break;
		}
		
		else if(s[i].ch!=s[r].ch){
			if(cntl<cntr){
				ans+=cntl;
				cntr=cntr-cntl;
				cr=s[r].ch;
				cl=0;
				cntl=0;
			}else if(cntl>cntr){
				ans+=cntr;
				cntl=cntl-cntr;
				cl=s[l].ch;
				cr=0;
				cntr=0;
			}else{
				ans+=cntl;
				cntl=0,cntr=0;
			}
		}else if(s[i].ch==s[r].ch){
			if(cntl<cntr){
				cntr=cntr-cntl;
				cr = s[r].ch;
				cntl=0;
				cl=0;
			}else if(cntl>cntr){
				cntl=cntl-cntr;
				cl = s[l].ch;
				cntr=0;
				cr=0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
