#include<iostream>
using namespace std;
const int MAXN=2e5+5;
int n;
long long a[MAXN],ans=0;
long long sum=0,s[MAXN];
char c[MAXN];
int pos=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i],s[i]=s[i-1]+a[i];
	}
	while (s[pos]<=sum/2) ++pos;
	int l,r;
	l=r=pos;
	long long cnt1=sum/2-s[pos-1],cnt2=s[pos]-(sum+1)/2;
	while (l>=1 && r<=n){
		long long minn=min(cnt1,cnt2);
		if (c[l]!=c[r]) ans+=minn;
		cnt1-=minn,cnt2-=minn;
		if (cnt1==0) cnt1=a[--l];
		if (cnt2==0) cnt2=a[++r];
	}
	cout<<ans;
	return 0;
}
// rp++;
