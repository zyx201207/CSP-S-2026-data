#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	char ch=getchar();
	ll x=0,f=1;
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void write(ll x){
	if(x<0) putchar('-');
	x=abs(x);
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	return 0;
}
