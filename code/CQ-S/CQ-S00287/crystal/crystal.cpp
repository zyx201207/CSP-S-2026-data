#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[550000];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,ans=1,p=0;
	for(int i=2;i<=n;i++){
		p+=(i-l)*(a[i]-a[i-1]);
		while(p>m){
			p-=(a[i]-a[l]);
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
/*
LUOGU UID:1274525
Genshin UID:331504998

write at 14:15
morning can SLEEP! 
afternoon affects one life.

Oct31==Dec25?  my answer:NO

write at 15:59
100+100+0+0=200
I have 6v!!!!

write at 16:42
100+100+24+0=224
I may have 7v!!!!

write at 17:26
I can't do it more now,my near student seem like XUN.(They may not solve T2)
CAN I arrive Winter Camp line? I want it.
Da Da Da Da Da,I want to play Genshin.
Da Da Da Da Da,Seeing the perfect a lot.
Da Da De Da Da Da Da De Da.
I ofhen ZHUIYI at last.
Do you now where am I? 

write at 18:00
I see wrong,T3 YANGLI4 is 11,12,I may solve 7~10.

So 100+100+[24,40]+0=[224,240]

write at 18:22
100+100+[32,48]+0=[232,248]!!!
*/
