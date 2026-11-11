#include<bits/stdc++.h>
#define N 500005
#define ll long long
using namespace std;
int n,m;
ll a[N];
ll read(){
	bool flag=false;
	char c;
	ll num=0;
	c=getchar_unlocked();
	while(!(c>='0'&&c<='9')){
		if(c=='-') flag=true;
		c=getchar_unlocked();
	}
	while(c>='0'&&c<='9'){
		num*=10;
		num+=c-'0';
		c=getchar_unlocked();
	}
	return flag?-num:num;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	ll num=0,ans=0,tot=0;
	for(int i=1;i<=n;i++){
		tot+=num*(a[i]-a[i-1]);
		num++;
		while(tot>m&&num>=1){
			tot-=(a[i]-a[i-num+1]);
			num--;
		}
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}
