#include<bits/stdc++.h> 
using namespace std;
const int N=5e5+10;
#define ll long long 
ll a[N];
int read(){
	ll x=0;
	int f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=read();
	ll m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();		
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	int l=2,r=1;
	int sum=0;//
	int ans=0;
	while(r<l&&l<=n){
		if(a[l]!=a[l-1]) sum+=a[l]-a[r];
		if(sum<=m){
			ans=max(ans,l-r+1);
		}
		else{
			sum-=a[l]-a[r];
			r++;
		}
		l++;
	}
	printf("%d\n",ans);
	return 0;
}
