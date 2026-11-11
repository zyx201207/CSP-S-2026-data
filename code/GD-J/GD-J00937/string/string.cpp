#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
#define si short int
using namespace std;
const int N=2e5+9;
ll n;
ll cnt[N],cnt2[N];
char a[N],a2[N];
ll ans;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1,j=n;i<=n;i++,j--) {
		scanf("%lld %c",&cnt[i],&a[i]);
		a2[j]=a[i],cnt2[j]=cnt[i];
	}
//	for(ll i=1;i<=n;i++) {
//		for(ll j=0;j<cnt[i];j++) cout<<a[i];
//	}
//	cout<<"\n";
//	for(ll i=1;i<=n;i++) {
//		for(ll j=0;j<cnt2[i];j++) cout<<a2[i];
//	}
//	cout<<"\n";
	ll l,l2;
	l=l2=0;//右边（下一个左） 
	for(ll i=1,j=1;i<=n;i++) {
//		cout<<"oper: ";
		ll la=l;
		l+=cnt[i];
		while(l>l2 && j<=n) {
			if(a[i]!=a2[j]) {
				if(l2+cnt2[j]>l) {
					if(i<n&&a[i+1]!=a2[j]) ans+=cnt2[j];
					else ans+=l-la;
//					cout<<"bA("<<l<<","<<la<<") ";
				}
				else {
					ans+=cnt2[j];
//					cout<<"bB ";
				}
			}
			else if(i<n&&a[i+1]!=a2[j]) {
				if(l2+cnt2[j]>l) {
					ans+=l2+cnt2[j]-l;
//					cout<<"bC ";
				}
			}
			l2+=cnt2[j],j++;
			la=l2;
		}
//		cout<<"\n"; 
//		cout<<l<<"("<<i<<")"<<" "<<l2<<"("<<j<<")"<<": "<<ans<<"\n\n";
	} 
	cout<<(ans>>1);
	return 0;
}

/*
不同的位数就是答案 

3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

5
1 a
1 b
1 a
1 b
1 a

2
6 a
1 b

2
1 a
6 b

*/
