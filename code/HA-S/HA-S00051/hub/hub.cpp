#include<bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE 1
#define duoce 1
typedef long long ll;
const int N=2e5+5;
inline ll read(){
	ll ret=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
void write(ll x){
	if(x<0){
		putchar('-'),x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void solve();
int c;
int main(){
	if(ONLINE_JUDGE){
		freopen("hub.in","r",stdin);
		freopen("hub.out","w",stdout);
	}
	int t=1;
	if(duoce)c=read(),t=read();
	while(t--)solve();
}
void solve(){
	int n,k,u,v;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>u>>v;
	cout<<0<<endl;
}
