//#include<bits/stdc++.h>
//#define int long long
//#define iint __int128
//#define f1(a,b,c) for(int i=a;i<=b;i+=c)
//#define f2(a,b,c) for(int j=a;j<=b;j+=c)
//#define f3(a,b,c) for(int i=a;i>=b;i-=c)
//#define f4(a,b,c) for(int j=a;j<=b;j-=c)
//#define au(k) for(auto v:k)
//using namespace std;
//int a[500005],d[500005],b[500005];
//signed main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
//	int n,m;
//	cin>>n>>m;
//	int ia=1,ib=1;
//	cin>>a[1];
//	if(a[1]!=1){
//		ia=0;
//	}
//	f1(2,n,1){
//		cin>>a[i];
//		d[i]=a[i]-a[i-1];
//		if(a[i]!=i){
//			ia=0;
//		}
//	}
//	if(ia){
//		iint cnt=0;
//		int ll=1,j=1;
//		while(cnt<=m&&n>=j++){
//			cnt+=ll;
//			ll++;
//		}
//		cout<<"ssss"<<ll-1; 
//		return 0;
//	}
//	f1(3,n,1){
//		if(d[i]!=d[i-1]){
//			ib=0;
//		}
//	}
//	if(ib){
//		iint cnt=0;
//		int j=1,ll=1;
//		while(cnt<=m&&n>=j++){
//			cnt+=ll*d[2];
//			ll++;
//		}
//		cout<<"sssssss"<<ll-1;
//		return 0;
//	}
//	sort(a+1,a+1+n);
//	b[1]=a[n]-a[1];
//	f1(2,n,1){
//		b[i]=a[n]-a[i];
//	}
//	int ans=1;
//	f1(1,n,1){
//		iint cnt=0;
//		int ll=1;
//		f2(i+1,n,1){
//			if(cnt+a[j]-a[j-1]>m){
//				break;
//			}else{
//				ll++;
//				cnt+=a[j]-a[j-1];
//			}
//		}
//		ans=max(ll,ans);
//	}
//	cout<<ans;
//	return 0;
#include<bits/stdc++.h>
#define int long long
#define iint __int128
#define f1(a,b,c) for(int i=a;i<=b;i+=c)
#define f2(a,b,c) for(int j=a;j<=b;j+=c)
#define f3(a,b,c) for(int i=a;i>=b;i-=c)
#define f4(a,b,c) for(int j=a;j<=b;j-=c)
#define au(k) for(auto v:k)
using namespace std;
int a[500005],b[500005],d[500005];
vector<iint> c(500005);
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ia=1,ib=1;
	cin>>a[1];
	if(a[1]!=1){
		ia=0;
	}
	f1(2,n,1){
		cin>>a[i];
		d[i]=a[i]-a[i-1];
		if(a[i]!=i){
			ia=0;
		}
	}
	if(ia){
		iint cnt=0;
		int ll=1,j=1;
		while(cnt<=m&&n>=j++){
			cnt+=ll;
			ll++;
		}
		cout<<ll; 
		return 0;
	}
	f1(3,n,1){
		if(d[i]!=d[i-1]){
			ib=0;
		}
	}
	if(ib){
		iint cnt=0;
		int ll=1,j=1;
		while(cnt<=m&&n>=j++){
			cnt+=ll*d[1];
			ll++;
		}
		cout<<ll;
		return 0;
	}
	sort(a+1,a+1+n);
	b[1]=a[n]-a[1];
	c[1]=b[1];
	f1(2,n,1){
		b[i]=a[n]-a[i];
		c[i]=c[i-1]+a[i];
	}
	int ans=1;
	f1(1,n,1){
		f2(i+1,n,1){
			if(c[j]-c[i-1]-(j-i+1)*b[j]<=m){
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans;
	return 0;
}

