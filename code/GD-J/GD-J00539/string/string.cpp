#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define un unsigned

const int N=2e5+5;

char c[N];
ll a[N],x=0,ans=0,k=0,h=0;
string s;
//void f(ll a1,ll a2){
//	if(a1==a2){
//		return ;
//	}
//	if(c[a1]!=c[a2]){
//		if(a[a1]>a[a2]){
//			ans+=a[a1]-a[a2];
//			a[a1]=a[a1]-a[a2],a[a2]=0;
//			f(a1,a2-1);
//		}
//		else if(a[a1]<a[a2]){
//			ans+=a[a2]-a[a1];
//			a[a1]=0,a[a2]=a[a2]-a[a1];
//			f(a1+1,a2);
//		}
//		else {
//			ans+=a[a1];
//			a[a1]=a[a2]=0;
//			f(a1+1,a2-1);
//		}
//	}
//	else{
//		if(a[a1]>a[a2]){
//			a[a1]=a[a1]-a[a2],a[a2]=0;
//			f(a1,a2-1);
//		}
//		else if(a[a1]<a[a2]){
//			a[a1]=0,a[a2]=a[a2]-a[a1];
//			f(a1+1,a2);
//		}
//		else {
//			a[a1]=a[a2]=0;
//			f(a1+1,a2-1);
//		}
//	}
//	return ;
//}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]){
			k=1;
		}
	}
	if(k==0){
		x=n;
		for(int i=1;i<=n;i++)	s+=c[i];
		ll mid=1ll*(x*1.0/2+0.5);
		un ll l=s.size();
		for(int i=0;i<mid;i++){
			if(s[i]!=s[l-i-1]){
				ans++;
			}
		}
		
		ans=ans*a[1];
	}
	else{
		for(int i=1;i<=n;i++){
			x+=a[i];
			for(int j=1;j<=a[i];j++)	s+=c[i];	
		}		
		ll mid=1ll*(x*1.0/2+0.5),g=0;
//		for(ll i=1;;i++){
//			if(g>=mid){
//				h=i;
//				break;
//			}	
//			g+=a[i];
//		}
		un ll l=s.size();
//		for(int i=1;i<h;i++){
//			f(i,n-i-1);
//		}
		for(int i=0;i<mid;i++){
			if(s[i]!=s[l-i-1]){
				ans++;
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}
/*
n 2e5
a 1e9
*/

