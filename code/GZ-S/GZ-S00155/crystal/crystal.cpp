//罗修哲 GZ-S00155 安顺市第一高级中学
#include<bits/stdc++.h>
using namespace std;
#define mxn int(5e5+10) 
int n;
long long m,a[mxn],rqst,lastnum;
long long read(){
	char c=getchar();
	long long num=0,w=1;
	while(c<'0'||c>'9'){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=num*10+c-'0';
		c=getchar();
	}
	return num*w;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){a[i]=read();}//scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=1,ans=0;//[l,r)
	while(l<=r&&r<=n+1){
		if(rqst<=m){
			if(ans<r-l){ans=r-l;}
			r++;
			rqst+=(r-l-1)*(a[r-1]-lastnum);
			lastnum=a[r-1];
		}
		else{
			rqst-=lastnum-a[l];
			l++;
		}
		//printf("%d %d %lld %lld %d %dll\n",l,r,lastnum,rqst,ans,a[r-1]);
	} 
	cout<<ans;
	return 0;
}
