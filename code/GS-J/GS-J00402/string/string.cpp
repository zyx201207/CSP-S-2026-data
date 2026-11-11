#include<bits/stdc++.h>
using namespace std;
long long n,cnt,ans,cntc,cntb,c,b;
struct str{
	int x;
	char s;
}a[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].s;
		cnt+=a[i].x;
	}cntc=1,cntb=n;
	c=a[cntc].x,b=a[cntb].x;
	for(int i=1;1;i++){
		if(cntc>=cntb) break;
		if(c<b){
			if(a[cntc].s==a[cntb].s) b-=c;
			else ans+=c,b-=c;
			c=0,cntc++;
			c+=a[cntc].x;
		}else if(c>b){
			if(a[cntc].s==a[cntb].s) c-=b;
			else ans+=b,c-=b;
			b=0,cntb--;
			b+=a[cntb].x;
		}else{
			if(a[cntc].s==a[cntb].s) b=0,c=0;
			else ans+=b;
			b=0,c=0,cntc++,cntb--;
			c=a[cntc].x,b=a[cntb].x;
		}
	}cout<<ans;
}

