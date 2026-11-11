// I spent too much time solving this problem.
// "How do you make that pain so perfect, my favourite person?"
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int N=2e5+5;
char c[N],d[N];
ll a[N],b[N],s[N*2],sum=0;
int n;
void solve1(){
	int ans=0;
	string str;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=a[i];j++) str=str+c[i];
	for(int i=0,j=sum-1;i<j;i++,j--)
		if(str[i]!=str[j]) ans++;
	cout<<ans<<"\n";
}
void solve2(){
	int len=0;
	for(int i=1;i<=n;i++){
		if(c[i]!=c[i-1]) b[++len]=a[i],d[len]=c[i];
		else b[len]+=a[i];
	}
	if(len==1){
		cout<<"0\n";
		return;
	}
	int cnt=0; ll tot=0; 
	for(int i=1;i<=len&&tot<sum/2;i++){
		tot+=b[i];
		if(tot>sum/2) tot=sum/2;
		s[++cnt]=tot;
	}
	tot=0;
	for(int i=len;i>=1&&tot<sum/2;i--){
		tot+=b[i];
		if(tot>sum/2) tot=sum/2;
		s[++cnt]=tot;
	}
	sort(s+1,s+cnt+1);
	cnt=unique(s+1,s+cnt+1)-s-1;
	for(int i=2;i<=len;i++)
		b[i]+=b[i-1];
	ll res=0;
	for(int i=1;i<=cnt;i++){
		int j=lower_bound(b+1,b+len+1,s[i])-b,
			k=lower_bound(b+1,b+len+1,sum-s[i]+1)-b;
		if(d[j]!=d[k]) res+=s[i]-s[i-1];
	}
	cout<<res<<"\n";
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(n==1){
		cout<<"0\n";
		return 0;
	}
//	if(sum<=1e5) solve1();
	solve2();
	return 0;
}

