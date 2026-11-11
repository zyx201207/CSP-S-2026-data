//GZ-S00362 ·¶Ë¼Ñî 
//#include<bits/stdc++.h>
//#define f(i,a,b) for(int i=(a);i<=(b);i++)
//#define ll long long
//#define V vector
//using namespace std;
//int n,m;
//V<int> a,b;
//int fct(int l,int r){
//	int s=0,j=1;
//	f(i,l+1,r){
//		s+=j*b[i];
//		j++;
//	}
//	return s;
//}
//int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
//	cin>>n>>m;
//	a.resize(n+2);
//	b.resize(n+2);
//	f(i,1,n){
//		cin>>a[i];
//	}
//	sort(a.begin()+1,a.end()-1);
//	f(i,1,n){
//		b[i]=a[i]-a[i-1];
//	}
////	int L=1,R=n,ans=0;
////	while(L>=R){
////		int d=fct(L,R);
////		if(d<=m){
////			ans=d;
////			
////		}
////	}
//	int ans=0; 
//	f(i,1,n){
//		f(j,i,n){
//			int d=fct(i,j);
//			if(d<=m)
//			ans=max(ans,j-i+1);
//		}
//	}
//	cout<<ans;
//	return 0;
//}
#include<bits/stdc++.h>
#define f(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
#define V vector
using namespace std;
int n;
ll m;
V<ll> a,b;
//V< V<int> >c;
ll fct(int l,int r){
	ll s=0,j=1;
	f(i,l+1,r){
		s+=j*b[i];
		j++;
	}
	return s;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a.resize(n+2);
	b.resize(n+2);
	f(i,1,n){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end()-1);
	f(i,1,n){
		b[i]=a[i]-a[i-1];
	}
	int ans=0,L=0,R=n-1,mid,Lp,Rp;
	while(L<=R){
		mid=(L+R)/2;
		Lp=L;
		Rp=R;
		if(fct(1,mid+1)<=m){
			L=mid;
			ans=max(ans,mid+1);
		}else{
			R=mid;
		}
		if(Lp==L and Rp==R)break;
	}
	cout<<ans;
	return 0;
}
