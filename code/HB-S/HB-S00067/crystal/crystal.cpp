#include<bits/stdc++.h>
#define int __int128
using namespace std;
int n,m,a[500005],sum[500005],ans=0;
int get(int t){
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid]<t)l=mid+1;
		else r=mid-1;
	}
	return l;
}
int read(){
	int x=0,y=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')y=-y;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
void print(int t){
	stack<char>st;
	while(t){
		st.push(t%10+'0');
		t/=10;
	}
	while(!st.empty()){
		cout<<st.top();
		st.pop();
	}
}
signed main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=n;i>=1;i--){
		if(i<ans)break;
		for(int j=1;j<=i;j++){
			if(i-j+1<ans)break;
			if((i-j+1)*a[i]-(sum[i]-sum[j-1])<=m)ans=max(ans,i-j+1);
		}
	}
	print(ans);
	return 0;
}
