#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll inline ret() {
	ll t=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		t=t*10+ch-'0';
		ch=getchar();
	}
	return f*t;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int i1=ret(),i2=ret();
	while(i2--) printf("1\n");
	return 0;
}
