#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ls,ans,idx;
struct st{
	int lp,len;
	char s;
	int hu;
}pos[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	char lc;
	int la=0;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		if(i==1){
			lc=c,la=a;
			continue;
		}
		if(c==lc){
			a+=la;
			if(i==n) pos[++idx].lp=ls,pos[idx].len=a,pos[idx].s=c,ls+=a;
		}
		else{
			pos[++idx].lp=ls,pos[idx].len=la,pos[idx].s=lc,ls+=la;
			if(i==n) pos[++idx].lp=ls,pos[idx].len=a,pos[idx].s=c,ls+=a;
		}
		lc=c,la=a;
	}
	int r=idx;
	for(int i=1;i<=idx;){
		if(i>r) break;
		int leni=pos[i].len-pos[i].hu,lenr=pos[r].len-pos[r].hu;
		if(pos[i].s==pos[r].s){
			if(leni>lenr){
				r--;
				pos[i].hu+=lenr;
			}
			else{
				i++;
				pos[r].hu+=leni;
			}
		}
		else{
			if(leni>lenr){
				
				pos[i].hu+=lenr;
				ans+=lenr;
				if(pos[r].lp<=ls/2&&ls/2<=pos[r].lp+lenr&&ls%2==1){
					ans--;
					cout<<pos[r].lp<<' '<<pos[r].lp+lenr<<'\n';
				}
				r--;
			}
			else{
				
				ans+=leni;
				pos[r].hu+=leni;
				if(pos[i].lp<=ls/2&&ls/2<=pos[i].lp+leni-1&&ls%2==1){
					ans--;
				}
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
} 

