#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ma=-1;
	bool f1=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		int x=1;
		bool f=false;
		for(int j=1;j<=30;j++){
			x*=2;
			if(a[i]==(x-1)){
				f=true;
			}
		}if(f==false){
			f1=false;
		}
	}if(f1==true){
		sort(a+1,a+n+1);
		int p=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			p&=a[i];
		}cout<<p;
		return 0;
	}int y=a[1];
	for(int i=2;i<=n;i++){
		y&=a[i];
	}if(m==n){
		cout<<y;
		return 0;
	}if(n<=2000&&m==1){
		cout<<ma;
		return 0;
	}int maa=-1;
	if(n<=2000&&m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int x=a[i]&a[j];
				maa=max(maa,x);
			}
		}cout<<maa;
		return 0;
	}
	return 0;
}
