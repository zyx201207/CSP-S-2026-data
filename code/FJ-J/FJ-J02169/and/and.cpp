#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=-1,a[200005],s[200005];
long long poow(int x){
	int a=1;
	for(int i=1;i<=x;i++){
		a*=2;
	}
	return a;
}
long long andd(int x,int y){
	int x2[31],y2[31];
	int num=0;
	int tmp=x;
	while(tmp){
		x2[num]=tmp%2;
		tmp/=2;
		num++;
	}
	int lx=num;
	num=0;tmp=y;
	while(tmp){
		y2[num]=tmp%2;
		tmp/=2;
		num++;
	}int ly=num;
	int k=0;
	int mlen=max(lx,ly);
	for(int i=0;i<mlen;i++){
		if(x2[i]==1&&y2[i]==1)k+=poow(i);
		//cout<<x2[i]<<' '<<y2[i]<<endl;
	}
	//cout<<x<<' '<<y<<' '<<k<<endl;
	return k;
}
void dp(int sum,int k,long long x){
	if(sum==m){
		ans=max(ans,x);
		return;
	}
	//cout<<x<<' ';
	for(int i=k+1;i<=n;i++){
		dp(sum+1,i,andd(x,a[i]));
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		dp(1,i,a[i]);
	}
	cout<<ans;
	return 0;
}
