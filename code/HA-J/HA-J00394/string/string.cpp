#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
ll len,l,r;
ll a[N],n;
char s[N];
char d[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	len=0;
	bool fa=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>s[i];
		len+=a[i];
		
		if(a[i]!=1){
			fa=0;
		}a[i]=len;
	}ll ans=0;
	if(fa){
		for(int i=1;i<=len/2;i++){
			if(s[i]!=s[len-i+1]){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}if(len<=50000000){
		for(int i=1;i<=n;i++){
			for(int j=a[i];j>a[i-1];j--){
				d[j]=s[i];
			}
		}
		for(int i=1;i<=len/2;i++){
			if(d[i]!=d[len-i+1]){
				ans++;
			}
		}cout<<ans;
		return 0;
	}
	l=1,r=len;
	ll li=1,ri=n,mid=(len+1)>>1;
	while(l<r){
		if(l>a[li]){
			li++;
		}if(r<=a[ri-1]){
			ri--;
		}
		int c1=a[li]+1-l;
		int c2=r-a[ri-1];
		if(c2<c1){
			r-=c2;
			l+=c2;
			if(s[li]!=s[ri]){
				ans+=c2;
			}
		}else{
			r-=c1;
			l+=c1;
			if(s[li]!=s[ri]){
				ans+=c1;
			}
		}
		//cout<<l<<" "<<r<<" "<<li<<" "<<ri<<"\n";
	}
	if(l>r){
		if(l>a[li]){
			li++;
		}if(r<=a[ri-1]){
			ri--;
		}
		if(s[li]!=s[ri]){
			ans-=(l-r)/2;
		}
	}
	cout<<ans;
	return 0;
}
/*
aabbc
*/
