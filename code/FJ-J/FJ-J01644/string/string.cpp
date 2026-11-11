#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int n,ans;
int a[maxn],b[maxn],c[maxn],d[maxn];
void solve(){
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		char ch;
		cin>>ch;
		c[i]=ch-'a';
		b[n-i+1]=a[i],d[n-i+1]=c[i];
	}
	int ls=0,rs=0,sl=0,sr=0;
	while(ls<n||rs<n){
		if(sl<sr){
			int x=sl;
			ls++;
			sl+=a[ls];
			int y=min(sl,sr),xc=c[ls],yc=d[rs];
			if(xc!=yc){
				ans+=y-x;
			}
		}else{
			int x=sr;
			rs++;
			sr+=b[rs];
			int y=min(sl,sr),xc=d[rs],yc=c[ls];
			if(xc!=yc){
				ans+=y-x;
			}
		}
	}
	cout<<ans/2<<"\n";
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}
