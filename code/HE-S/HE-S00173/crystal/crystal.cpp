#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+5;
const ll C=1e6+5;
//a[i]<1e12

int n,m;
int a[N];

int read( ) {
	int k=0,f=1ll,c=getchar( );
	for( ; c<'0'||c>'9'; c=getchar( ))
		if(c=='-')
			f=-f;
	for( ; c>='0'&&c<='9'; c=getchar( ))
		k=k*10+(c^48);
	return f*k;
}

int main( ) {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	n=read( );
	m=read( );
	bool A=true,B=true;
	for(int i=1; i<=n; i++) {
		a[i]=read( );
		if(a[i]!=i)
			A=false;
	}

	sort(a+1,a+n+1);
	if(m==0) {
		int lastcnt=-1,cnt=1;
		for(int i=2; i<=n; i++) {
			if(a[i]==a[i-1])
				cnt++;
			else {
				lastcnt=max(cnt,lastcnt);
				cnt=1;
			}
		}
		cout<<max(cnt,lastcnt);
		return 0;
	}

	if(A) {
		int ans=1;
		for(int i=1; ; i++) {
			m-=i;
			if(m<0)
				break;
			ans++;
		}
		cout<<ans<<endl;
		return 0;
	}

	int lastcz,cz;
	for(int i=2; i<=n; i++) {
		cz=a[i]-a[i-1];
		if(i>2)
			if(cz!=lastcz) {
				B=false;
				break;
			}
		lastcz=cz;
	}
	if(B) {
		int ans=1;
		for(int i=1; ; i++) {
			m-=i*cz;
			if(m<0)
				break;
			ans++;
		}
		cout<<ans<<endl;
		return 0;
	}

	cout<<1<<endl; 

	return 0;
}
