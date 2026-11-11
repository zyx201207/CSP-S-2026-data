//AC++
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<climits>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#define int long long
using namespace std;
int n,R,len=0,ans;
int q[200010];
struct Code{
	int some,l,r;
	char ch;
}a[200010];
int ef(int findd){
	int L=1,R=n;
	while(L<R){
		int mid=(L+R)/2;
		if(a[mid].r>=findd) R=mid;
		else L=mid+1;
	}
	return L;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>a[1].some>>a[1].ch,a[1].l=0,a[1].r=a[1].some-1,R=a[1].r+1;
	for(int i=2;i<=n;i++) cin>>a[i].some>>a[i].ch,a[i].l=R,a[i].r=a[i].l+a[i].some-1,R=a[i].r+1;
	for(int i=1;i<=n;i++) q[i]=len+=a[i].some;
	for(int i=1;i<=n;i++){
		int L=a[i].l,R=min(a[i].r,len/2); 
		if(L>=len/2) break;
		int Ls=ef(len-L-1),Rs=ef(len-R-1);
		swap(Ls,Rs);
		int beginn=(len-R)-q[Ls-1],end=(len-L)-q[Rs-1];
		for(int j=Ls;j<=Rs;j++) 
			if(j==Ls&&a[j].ch!=a[i].ch) ans+=a[Ls].some-beginn+1;
			else if(j==Rs&&a[j].ch!=a[i].ch) ans+=end;
			else if(a[j].ch!=a[i].ch) ans+=a[j].some;
	}
	cout<<ans;
	return 0;
}
