#include<bits/stdc++.h>
using namespace std;
__int128 n,m,a[500005],sum[500005];
inline __int128 read(){
	__int128 x=0,f=1;char ch=getchar();
	while(!isdigit(ch))ch=='-'?f=-1:f=f,ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
bool check(int x){//check x crystal 
	__int128 daijia=1e18;
	for(int i=x;i<=n;i++){
		__int128 xx=x;
		daijia=min(daijia,1ll*a[i]*xx-(sum[i]-sum[i-xx]));
	}if(daijia<=m)return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	
	for(int i=1;i<=n;i++){
		a[i]=read();
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l<<endl;
	return 0;
}

