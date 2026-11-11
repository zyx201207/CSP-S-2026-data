#include<bits/stdc++.h>
#define int long long
using namespace std;
int rd(){
	int x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9')f|=ch=='-',ch=getchar();
	do{x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}while(ch>='0'&&ch<='9');
	return f?-x:x;
}
int n,m,a[500001],l,sum,s;
signed main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	n=rd(),m=rd();
	for(int i=1;i<=n;i++)a[i]=rd();sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		while(a[i]*(i-l-1)-sum>m&&l<i)sum-=a[++l];
		s=max(s,i-l),sum+=a[i];
	}
	printf("%lld",s);
	return 0;
} 
