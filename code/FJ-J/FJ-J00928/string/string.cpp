#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
using namespace std;

const int N=2e5+5;

int n,len,l[N],r[N];
char c[N];

#define rev(x) ((len)-(x)+(1))

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	fast;
	cin>>n;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		cin>>c[i];
		l[i]=r[i-1]+1;
		r[i]=l[i]+x-1;
		len+=x;
		//cout<<l[i]<<' '<<r[i]<<'\n';
	}
	int pl=1,pr=n;
	int ans=0;
	while(pl<=pr){
		int revl=rev(r[pr]),revr=rev(l[pr]);
		int ml=l[pl],mr=r[pl];
		if(c[pl]!=c[pr]){
			ans+=min(revr,mr)-max(revl,ml)+1;
			//cout<<"upd:"<<max(revl,ml)<<' '<<min(revr,mr)<<'\n'<<pl<<' '<<pr<<'\n';
		}
		if(mr<revr) ++pl;
		else if(mr>revr) --pr;
		else ++pl,--pr;
	}
	cout<<ans;
	return 0;
}

