#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace FastIO{
	template<class T>
	T read(T&x){
		x=0;bool f=false;char ch=getchar();
		while(!isdigit(ch)) f|=!(ch^'-'),ch=getchar();
		while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch&0xF),ch=getchar();
		if(f) x=-x;return x;
	}
	template<class T>
	void write(T x,char ch=' '){
		if(x<0) putchar('-'),x=-x;
		int cnt=0;char tmp[41];
		while(x>9) tmp[cnt++]=x%10+'0',x/=10;tmp[cnt++]=x+'0';
		while(cnt) putchar(tmp[--cnt]);putchar(ch);
	}
}
using namespace FastIO;
const int N=5e5+10;
ll a[N],m;
int n,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	read(n),read(m);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	ll sum=0;
	for(int l=1,r=1;r<=n;r++){
		while(l<r&&sum>m) sum-=a[r]-a[l],l++;
		ans=max(ans,r-l+1);
		sum+=(r-l+1)*(a[r+1]-a[r]);
	}
	write(ans,'\n');
	
	fclose(stdin);fclose(stdout);
	return 0;
}
