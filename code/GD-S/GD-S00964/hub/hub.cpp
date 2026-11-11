#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
ll n,m,bl=1,cnt=0,t,c;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();
	t=read();
	while(t--){
		n=read();
		m=read();
		for(int i=1;i<n;i++){
			int a,b;
			a=read();
			b=read();
		}
//		cout<<n<<" "<<m;
		while(m*bl<n){
//			cout<<bl<<'\n';
			bl+=2;
			cnt++;
		}
		cout<<cnt;
	}
	return 0;
}
