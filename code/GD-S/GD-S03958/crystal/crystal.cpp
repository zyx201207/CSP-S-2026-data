#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
const int M=1e9;
int n,m;
int a[N];
int fc[N];
int dp[N][M];
int ot=-1;

int cd1(int x,int y){
	while(y<=N-10){
		if(a[x]==a[y]){
			int xx=x*2;
			int yy=y*2;
			cd1(xx,yy);
		}else return false;	
	}
	return true;
}
int cd2(int x,int y,int d){
	while(y<=N-10){
		int ad=a[y]-a[x];
		ad%=d;
		if(y-x==ad) {
			x*=11;
			y*=7;
			cd2(x,y,d);			
		}else return false;
	}
	return true;
}

int panduan(int c,int d,int e){
	int len=d*(fc[e+1]-fc[e]);
	while(c-len>=0){
		d++;
		e++;
		c-=len;
		len=d*(fc[e+1]-fc[e]);
	}
	return d;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.ont","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]==a[2]){
		if(cd1(1,2)!=0) {
			cout<<n;
			return 0;
		}
	}
	if(a[2]-a[1]==a[3]-a[2]){
		int a_a=a[2]-a[1];
		if(cd2(2,4,a_a)!=0){
			int re=m/a_a;
			cout<<re;
			return 0;
		}
	}
	sort(a,a+n);
	memset(fc,0,sizeof(fc));
	for(int i=1;i<=n;i++){
		fc[i]=a[i]-a[1];
	}
	for(int i=1;i<=n;i++){
		int j=m;
		int ans=1;
		ot=max(panduan(j,ans,i),ot);
	}
	cout<<ot;
	return 0;
} 
