#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt=0,mid,m,ans=0,p[200005],l,r,midbs;
char c[200005];
vector<char>v;
char bs(int x) {
	l=1,r=cnt;
	while(l+1<r) {
		midbs=floor((l+r)/2);
		if(p[midbs-1]>x) {
			r=midbs-1;
//			cout<<'r';
		}
		else {
			l=midbs;
//			cout<<'l';
		}
	}
	if(p[l-1]>=x) return c[l-1];
	return c[r-1];
} 
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	v.push_back(char(0));
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++) {
			v.push_back(c[i]);
		}
		cnt+=a[i];
		p[i]=p[i-1]+a[i];
	}
	c[0]=c[1];
	if(cnt&1) {mid=int(floor(cnt/2))+1;m=cnt+1;}
	else {mid=cnt/2;m=cnt;}
	for(int i=1;i<=mid;i++) {
		ans+=(v[i]!=v[cnt+1-i]);
//		/*DEBUG*/printf("v[%d]=%c v[%d+1-%d(=%d)]=%c\n",i,v[i],cnt,i,cnt+1-i,v[cnt+1-i]);
//		if(bs(i)!=bs(cnt+1-i)) {
//			ans++;
//		}
//		/*DEBUG*/printf("bs(%d)=%c bs(%d+1-%d)=%c\n",i,bs(i),cnt,i,bs(cnt+1-i));
	}
	cout<<ans;
//	cout<<bs(5);
	return 0;
}
