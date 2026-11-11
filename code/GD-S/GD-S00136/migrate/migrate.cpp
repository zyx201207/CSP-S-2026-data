#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long p=1,num=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')p=-p;
		c=getchar();
	}
	while(isdigit(c)){
		num=num*10+c-'0';
		c=getchar();
	}
	return num*p;
}
long long c,t,n,a[2000010],d;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--){
		n=read();d=read();
		long long ans=0;
		for(long long i=1;i<=n;i++)a[i]=read();
		for(long long l=1,r=1;l<=n;l++){
			for(;a[r+1]-a[r]<=d&&r+1<=n&&r-l+2<=4;r++);
			if(r-l+1>3)ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2 5 3 -2 -1 0 1 2 6 2 -4 -3 -2 -1 3 6
*/
