#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0; char ch; bool f=0;
	while(((ch=getchar())<'0'||ch>'9')&&ch!='-') ;
	if(ch=='-') f=1;
	else x=(ch^48);
	while((ch=getchar())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48);
	return f?-x:x; 
}
const int N=5e5+55;
int n;
ll m,a[N],s1[N];
int main(){
//	system("fc crystal4.ans crystal.out"); return 0;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s1[i]=s1[i-1]+a[i];
	}
	int ans=1;
	for(int i=1,j=1;i<=n;i++){
		while(j<=i){
			ll t=s1[i]-s1[j-1];
			t=a[i]*(i-j+1)-t;
			if(t<=m) break;
			j++;
		}
		ans=max(ans,i-j+1);
	}
	printf("%d\n",ans);
	return 0;
}
/*
枚举最大值
双指针，区间和 
*/
