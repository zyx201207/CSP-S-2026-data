#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+3;
int n,len,b[N],t;//bÎªÇ°×ººÍ 
char c[N];
signed main(){
	ios::sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>t>>c[i];
		len+=t;
		b[i]=b[i-1]+t;
	}
	int mid=len/2+len%2,ans=0;
	char cc,cp;
	int cur=1,cur2=n;
	for (int i=1;i<=mid;i++){
		if (i>b[cur]) cc=c[cur+1],cur++;
		if (len-i+1<b[cur2]) cp=c[cur2-1],cur2--;
		if (cc!=cp) ans++;
	}
	cout<<ans;
}
