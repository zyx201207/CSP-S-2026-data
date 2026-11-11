#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,m,ans,A,B,a[N],b[N];char ch[N],c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i]>>ch[i],m+=a[i];
	int lim=(m+1)/2;
	for(int i=1,s=0;i<=n;++i){
		if(s+a[i]>=lim){
			A=i,b[++B]=a[i]-(lim-s),a[i]-=b[B],c[B]=ch[i];if(!b[B])--B;
			for(++i;i<=n;++i)b[++B]=a[i],c[B]=ch[i];
		}s+=a[i];
	}
	reverse(b+1,b+B+1),reverse(c+1,c+B+1);
	char la=-1,lb=-1;
	for(int i=1,j=1,sa=0,sb=0,v;i<=A;++i){
		sa+=a[i],la=ch[i],
		v=min(sa,sb),sa-=v,sb-=v,ans+=v*(la!=lb);
		while(j<=B&&sa)
			sb+=b[j],lb=c[j],++j,
			v=min(sa,sb),sa-=v,sb-=v,ans+=v*(la!=lb);
	}
	cout<<ans<<'\n';return 0;
}
