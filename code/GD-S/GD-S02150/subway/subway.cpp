#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
const int MX=1e9;
int a[N];
int n,m;

int check(int x){
	
	int d[N];
	for(int i=1;i<=n;i++){
		d[i]=abs(a[i]-x); 
	} 
	sort(d+1,d+n+1);
	
	int ans=0;
	int mt=m;
	for(int i=1;i<=n;i++){
		if(mt>=d[i]){
			mt-=d[i];
			ans++;
		}else break;
	}
	return ans;
	
}


signed main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m ;
	
	int mx=-MX,mi=MX,dt=1,sum=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		sum+=a[i];
		if(i>=3 && a[i]-a[i-1]!=a[i-1]-a[i-2]) dt=0;
		if(mx<a[i]) mx=a[i];
		if(mi>a[i]) mi=a[i];
	}
	
	if(dt==1){
		cout<<check(sum/n);
		return 0;
	}
	int mxans=0;
	for(int i=mi;i<=mx;i++){
		int tans=check(i);
		if(mxans<tans) mxans=tans;
	}
	cout<<mxans;
	return 0;
} 
