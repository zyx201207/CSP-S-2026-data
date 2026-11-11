#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
inline long long read(){
	long long f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int n;
long long m,a[N],cnt[N],ans=0,c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	sort(a+1,a+1+n);
	cnt[0]=c[0]=0;
	for(int i=1;i<n;++i){
		c[i]=a[i+1]-a[i];
		cnt[i]=cnt[i-1]+c[i];
	}
	long long i=1,j=1,res=c[i];
	while(i<=j&&j<n){
		while(res<=m&&j<n) j++,res+=(j-i+1)*c[j];
		ans=max(ans,j-i+1);
		int t=cnt[j]-cnt[i-1];
		res-=t;
		i++;
	}
	cout<<ans;
	return 0;
}
