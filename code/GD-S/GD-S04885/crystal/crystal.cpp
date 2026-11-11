#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MX=5e5+5;
int n;
int m;
int a[MX];
int t,t1;
bool f1=true,f2=true;
bool cmp(int x,int y){
	return x<y;
}
int f(int i,int j){
	int cnt=0;
	for(int x=j;x>=i;x--)cnt+=(a[j]-a[x]);
	return cnt;
}
void case1(){
	int x=0;
	int i=0;
	while(1){
		i+=t;
		x+=i;
		if(x+i+t>m)break;
	}
	cout<<i+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)f1=false;
		t=a[i]-a[i-1];
		t1=a[i+1]-a[i];
		if(t!=t1)f2=false;
	}
	if(f1==true||f2==true){
		case1();
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	int def=0;
	int tol=0,ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			def=f(i,j);
			if(def>m)break;
			else tol++;
		}
		if(tol>ans)ans=tol;
		def=0;
		tol=0;
	}
	cout<<ans;
	return 0;
} 
