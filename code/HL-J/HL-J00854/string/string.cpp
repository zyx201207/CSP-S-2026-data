#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+9;
int n;
ll a[N],L,lcnt,rcur,ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	rcur=a[n];
	bool flag=1;
	for(int l=1,r=n;flag;l++){
		lcnt+=a[l];
		ll llen=a[l];
		if(lcnt>L/2)
			llen-=lcnt-L/2,flag=0;
		while(llen>=rcur){
			if(c[l]!=c[r])
				ans+=rcur;
			llen-=rcur;
			rcur=a[--r];
		}
		if(llen){
			if(c[l]!=c[r])
				ans+=llen;
			rcur-=llen;
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
6 
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/