#include <bits/stdc++.h>
using namespace std;
long long m,n,a[200005],ans;
long long ze(long long x){
	long long y[32]={},y2=0,cnt=0;
	while(x>0){
		cnt++;
		y[cnt]=x%2;
		x/=2;
	}
	for(long long i=cnt;i>=1;i--){
		y2=y2*10+y[i];
	}
	return y2;
}
long long zs(long long x){
	long long wq=0,y=0;
	while(x>0){
		if(wq==0){
			y+=x%10*1;
		}
		else{
			long long sum=1;
			for(long long i=1;i<=wq;i++){
				sum*=2;
			}
			y+=x%10*sum;
		}
		wq++;
		x/=10;
	}
	return y;
}
bool cmp(long long a,long long b){
	return a>b;
}
void anda(long long x,long long y){
	long long x2[32],y2[32],ansand[32];
	long long xcnt=0,ycnt=0;
	while(x>0){
		xcnt++;
		x2[xcnt]=x%10;
		x/=10;
	}
	while(y>0){
		ycnt++;
		y2[ycnt]=y%10;
		y/=10;
	}
	long long cnt=min(xcnt,ycnt);
	for(long long i=1;i<=cnt;i++){
		if(x2[i]==y2[i]){
			ansand[i]=1;
		}
		else{
			ansand[i]=0;
		}
	}
	for(long long i=1;i<=cnt/2;i++){
		long long t=ansand[i];
		ansand[i]=ansand[cnt-i+1];
		ansand[cnt-i+1]=t;
	}
	long long andans=0;
	for(long long i=1;i<=cnt;i++){
		andans=andans*10+ansand[i];
	}
	ans=zs(andans);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=2;i<=m;i++){
		anda(ze(a[i-1]),ze(a[i]));
	}
	cout<<ans;
	return 0;
}
