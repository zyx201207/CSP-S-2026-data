#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n;
struct p{
	ll a;
	char c;
}a[N];
ll l,mid,ans;
char mi;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%s",&a[i].a,&a[i].c),l+=a[i].a;
	if(n%2==0){
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n/2-1;i++)
			if(a[i].c==a[i+1].c)cnt1++;
		for(int i=n/2+1;i<=n-1;i++)
			if(a[i].c==a[i+1].c)cnt2++;
		if((cnt1+1==n/2)||(cnt2+1==n/2)){
			cout<<l/2;
			return 0;
		}
	}
	for(int i=1;i<=n;i++)a[i].a+=a[i-1].a;
	int cnt1=0,cnt2=1,cnt3=n;
	while(cnt2<=cnt3){
		if(cnt1>a[cnt2].a)cnt2++;
		if(l+1-cnt1<a[cnt3].a)cnt3--;
		cnt1++;
		if(a[cnt2].c!=a[cnt3].c)ans++;
	}		
	cout<<ans;
	return 0;
}
