#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N=2e5+5;
int n;
ll ans;
struct node{
	ll a;
	char c;
}t[N]; 
inline ll read(){
	ll x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10LL+(c-'0');
		c=getchar();
	}
	return x;
}
inline void write(ll x){
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int main(){
//	freopen("string1.in","r",stdin);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		t[i].a=read();
		char s;
		scanf("%c",&s);
		while(s<'a'||s>'z') scanf("%c",&s);
		t[i].c=s;
	}
	int la=n;
	for(int i=1;i<=n;i++){
		if(i==la) break;
		for(int j=la;j>i;j--){
			if(t[i].a>t[j].a){
				if(t[i].c!=t[j].c) ans+=t[j].a;
				t[i].a-=t[j].a; t[j].a=0; la--;
			}else{
				if(t[i].c!=t[j].c) ans+=t[i].a;
				t[j].a-=t[i].a; t[i].a=0;
				if(t[j].a==0) la--;
			}
			if(t[i].a==0) break;
		}
	}
	write(ans);
	return 0;
}
