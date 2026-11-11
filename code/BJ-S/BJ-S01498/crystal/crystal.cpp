#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define CS 500005
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f*=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,a[CS],b[CS],ans=0,w;
bool cmp(int d,int c){
	return d<c;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i]-a[(n+1)/2]>0){
			w=i-1;
		}
		b[i]=a[i]-a[(n+1)/2];
	}
	for(int i=w;i>=1;i--){
		m+=b[i];
		ans++;
		if(m<0){
			ans--;
			break;
		}
	}
	if(m>0){
		for(int i=w+1;i<=n;i++){
			m-=ans*b[i];
			ans++;
			if(m<0){
				ans--;
				break;
			}
		}
	}
	cout<<max(ans,0ll);
	return 0;
}
//Oct31==Dec25?
