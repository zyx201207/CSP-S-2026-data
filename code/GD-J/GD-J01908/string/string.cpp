#include<bits/stdc++.h>
#define LL long long
#define P(i,s,t) for(int i=s;i<=t;++i)
#define S(i,s,t) for(int i=s;i>=t;--i)
using namespace std;
const int N=2e5+5;
int n,l,r;
char b[N];
LL a[N],ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n,l=1,r=n;
	P(i,1,n) cin>>a[i]>>b[i];
	while(l<r){
		if(a[l]>=a[r]){
			if(b[l]!=b[r]) ans+=a[r];
			a[l]-=a[r];
			r--;
		}else{
			if(b[l]!=b[r]) ans+=a[l];
			a[r]-=a[l];
			l++;
		}
	}
	cout<<ans;
	
	return 0;
}
