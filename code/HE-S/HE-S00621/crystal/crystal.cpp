#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],m,sum[N];
int s[N],hea,tai,n;
bool check(int x){
	hea=1;tai=0;
	for(int i=1;i<=x-1;i++){
		while(hea<=tai&&s[hea]+x<=i)hea++;
		while(hea<=tai&&a[s[tai]]<=a[i])tai--;
		s[++tai]=i;
	}
	long long noww;
	for(int i=x;i<=n;i++){
		while(hea<=tai&&s[hea]+x<=i)hea++;
		while(hea<=tai&&a[s[tai]]<=a[i])tai--;
		s[++tai]=i;
		noww=(a[s[hea]]*x)-(sum[i]-sum[i-x]);
		if(noww<=m)return 1;
	}
	return 0;
}
long long read(){
	long long k=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';c=getchar();
	}
	return k*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=0,r=n,mid,ans;
	while(l<=r){
		mid=(l+r)>>1;
//		cout<<"Begin"<<l<<" "<<r<<" "<<mid<<'\n';
		if(check(mid)){
			ans=mid;l=mid+1;
		}
		else r=mid-1;
//		cout<<"End"<<l<<" "<<r<<" "<<mid<<'\n';
	}
	cout<<ans;
	return 0;
}
/*5 8
-3 -1 2 2 7
*/
/*5 5
2 1 2 4 8 9
*/
