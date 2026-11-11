//刘科 GZ-S00100 安顺市第二高级中学

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int kMaxN=2e6+9;
int c,t,num,cont,ans;
int n,a[kMaxN],m;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--){

		n=read();m=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		num=abs(a[n]-a[n-1]);
		cont=m/num;
		if(n-(cont+cont)+1<=0||cont<=1){
			cout<<0<<'\n';
		}else{
			cout<<n-(cont+cont)+1<<'\n';
		}

	}
	return 0;
}
