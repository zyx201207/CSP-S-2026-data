#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define int long long
int s[N];
int n,m,ans,L,cnt;
int le,ri;
struct node{
	int l;
	char c;
}a[N],b[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i].l);
		scanf("%s",&a[i].c);
		L+=a[i].l;
	}for(int i=1;i<=n;++i){
		if(a[i].c==a[i-1].c){
			b[cnt].l+=a[i].l;
		}else{
			cnt++;
			b[cnt].l=a[i].l;
			b[cnt].c=a[i].c;
		}s[cnt]=s[cnt-1]+b[cnt].l;
		if(2*s[cnt-1]<L&&2*s[cnt]>=L&&L%2==1){
			b[cnt].l--;
			L--;
			s[cnt]--;
		}
		if(2*s[cnt]>=L&&m==0) m=cnt;
	}ri=m;
	if(s[m-1]==L/2) le=m-1;
	else le=m;
	while(le>0&&ri<=cnt){
		if(b[le].c!=b[ri].c){
			ans+=min(L/2-s[le-1],s[ri]-L/2)-max(max(L/2-s[le],(long long)0),max(s[ri-1]-L/2,(long long)0));
		}if(L/2-s[le-1]<s[ri]-L/2){
			le--;
		}else{
			ri++;
		}
	}cout<<ans;

	return 0;
}
