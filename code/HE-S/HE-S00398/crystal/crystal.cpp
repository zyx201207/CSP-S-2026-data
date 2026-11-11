#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long w=0,f=1;char c=getchar();
	while(c<'0'||c>'9')
	{if(c=='-')f=-1;
	c=getchar();}
	while(c>='0'&&c<='9')w=w*10+c-'0',c=getchar();
	return w*f;
}
const int H=5e5+10;
long long n,m;
long long h[H];
int mx=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		h[i]=read();
	}
	sort(h+1,h+n+1);
	__int128 sum=0;
	for(int i=1,j=1;i<=n;i++,sum+=(__int128)(i-j)*(h[i]-h[i-1])){
		while(sum>m){
			sum-=h[i]-h[j];
			++j;
		}
		mx=max(mx,i-j+1);
	}
	cout<<mx;
	return 0;
} 
