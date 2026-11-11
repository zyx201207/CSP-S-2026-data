#include <bits/stdc++.h>
using namespace std;
using lo=long long;
const lo N=2e5+10;
lo n;
lo sum;
lo b[N],e[N],len[N];
char c[N];
lo lid,rid,ll,lr,rl,rr;
lo lleft,rright,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		b[i]=sum+1;
		cin>>e[i]>>c[i];
		sum+=e[i];
		e[i]+=b[i]-1;
		len[i]=e[i]-b[i]+1;
	}
	lid=1,rid=n;
	ll=1,rl=1;
	lr=len[1],rr=len[n];
	while((lr<=(sum+1)/2||rr<=(sum+1)/2)&&lid<=n&&rid>0){
		lleft=max(ll,rl);
		rright=min(lr,rr);
		lo lenn=rright-lleft+1;
		if (c[lid]!=c[rid]){
			ans+=lenn;
		}
		if (lr>rr){
			rid--;
			rl=rr+1;
			rr=rl+len[rid]-1;
		}
		else{
			lid++;
			ll=b[lid];
			lr=e[lid];
		}
	}
	cout<<ans;
	return 0;
}
