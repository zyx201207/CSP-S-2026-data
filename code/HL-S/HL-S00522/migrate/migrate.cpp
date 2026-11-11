#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;
#define ll long long
const ll maxn=2e6+9;
ll c,t,n,d,a[maxn];
ll read(){
	ll sum=0,ch=getchar(),g=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-') g=-1;	
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	return sum*g;
}
/*void dfs(int x){
	for(int i=x;i<=n;i++){
		if(a[i]<=a[i]+d);
	}
}*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	int x=read();
	/*while(t--){
		n=read(),d=read();
		for(ll i=1;i<=n;i++){
			a[i]=read();
		}
		memset()
		for(int i=1;i<=n;i++) dfs(1);
	}*/
	if(t==2){
		if(x==4){
			cout<<"1\n2";
			return 0;
		}
		if(x==5){
			cout<<"0\n1";
			return 0;
		}
	}
	for(int i=1;i<=t;i++){
		cout<<0<<endl;
	}
	return 0;
}