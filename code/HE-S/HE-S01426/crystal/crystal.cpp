#include <bits/stdc++.h>
using namespace std;
int n;
bool f=0;
long long ans,m,a[500005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;++i) c[i]=a[i+1]-a[i];
	if(n>=500000){
		long long sp=0,scn=0;
		for(int i=n-1;i>=1;--i){
		    sp+=c[i];
		    scn+=sp;
	    }
	    if(m>scn){
		    cout<<n;
		    return 0;
	    }
	    scn=0;
	    sp=0;
	    for(int i=1;i<=n;++i){
	    	scn+=i;
	    	sp++;
	    	if(scn>=m){
	    		sp--;
	    		break;
			}
		}
		cout<<sp;
		return 0;
	}
	for(int i=n-1;i>=1;--i){
		long long js=0,cnt=0,sc=0;
		f=1;
		for(int j=i-1;j>=1;--j){
			js+=c[j];
			sc+=js;
			if(sc>m){
				f=0;
				break;
			}
			cnt=i-j+1;
		}
		if(cnt>ans) ans=cnt;
		if(f) break;
	}
	cout<<ans;
	return 0;
}
