#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+10;
LL n,a[N],ans1,ans2;
char c[N];
LL l=1,r,lt=1,rt;
void try56_64(){
	rt=a[n],r=n;
	while(l<r||(lt<rt&&l==r)){
		if(c[l]!=c[r]) ans1++;
		if(lt==a[l]) l++,lt=1;
		else lt++;
		if(rt==1) r--,rt=a[r];
		else rt--;
	}
}
void try_100(){
	r=n;
	while(l<r){
		if(c[l]!=c[r]){
			if(a[l]>a[r]) ans2+=a[r];
			else ans2+=a[l];
		}
		if(a[l]>a[r]) a[l]-=a[r],r--;
		else a[r]-=a[l],l++;
	}
}
int main(){//56-64
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	if(n==1){
		cout<<0;
		return 0;
	}
	for(LL i=1;i<=n;i++) cin>>a[i]>>c[i];
	try56_64();
	//try_100();
	printf("%lld",ans1);
	return 0;
}
