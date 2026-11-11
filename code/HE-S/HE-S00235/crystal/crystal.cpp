#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m;
const int maxn=5e5+5;
ll a[maxn];
ll ls[maxn],rs[maxn],cha[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll c=a[2]-a[1];
	ll t=1,sum=0;
	while(sum*c<m){sum+=t;t+=1;
	}
	cout<<min((int)t-1,n)<<endl;
//	cout<<((int)sqrt(1+8*m)-1+2)/2<<endl;
//	for(int i=1;i<=n;i++){
//		cha[i]=a[n]-a[i];
//		ls[i]=ls[i-1]+cha[i];
//	}
//	for(int i=n;i>=1;i--){
//		rs[i]=rs[i+1]+cha[i];
//	}
////	//
////	for(int i=1;i<=n;i++)cout<<ls[i]<<" ";
////	cout<<endl;
////	for(int i=1;i<=n;i++)cout<<rs[i]<<" ";
////	cout<<endl;
////	//
//	ll l=0,r=n;
//	ll mx=rs[1];
////	cout<<"mx="<<mx<<endl;
//	if(m>=rs[1]){
//		cout<<n<<'\n';
//		return 0;
//	}
//	while(l<r){
//		ll scmid=(a[r]-a[r-1])*(r-l-1);
//		ll scl=ls[l],scr=rs[r]+scmid;
////		cout<<scl<<" "<<scr<<endl<<l<<" "<<r<<endl;
//		if(scl+scr+scmid+m>=mx){
//			cout<<(r-l-1);
//			return 0;
//		}
//		if(scl<scr-scmid)r--;
//		else l++;
//	}
	return 0;
}
