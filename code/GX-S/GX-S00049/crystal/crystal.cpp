#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long m,ans=0,n,cha;
bool cmp(long long x,long long y) {return x<y;}
void ans1(){
	long long cnt=cha,cha2=cha,i=1;
	while(m>=cnt&&i<n){
		ans++;
		cha+=cha2;
		cnt+=cha;
		i++; 
	}
	ans++;
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool f=1;
	cin>>a[1]>>a[2];
	cha=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		long long cha1=a[i]-a[i-1];
		if(cha!=cha1) f=0;
	}	
	if(f) ans1();
	else{
	sort(a+1,a+n+1,cmp);
	for(long long l=1;l<=n;l++){
		for(long long r=l+1;r<=n;r++){
			long long cnt=0;
			long long maxv=a[r];
			for(long long i=l;i<=r;i++) cnt+=maxv-a[i];
			if(m>=cnt) ans=max(ans,r-l+1);
			else break;
		}
	}
	cout<<ans;
}
	return 0;
}
