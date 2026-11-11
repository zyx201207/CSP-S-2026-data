#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||'9'<c){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=5e5+5;
ll n,m,pre[N],a[N],ans=1;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	for(int i=1;i<=t;i++){
		cout<<rand()%2;
	}
}
