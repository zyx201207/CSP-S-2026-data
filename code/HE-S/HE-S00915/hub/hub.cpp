#include<bits/stdc++.h>
using namespace std;

int read(){
	int f=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}
void out(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<10)putchar(x+'0');
	else{
		out(x/10);
		putchar(x%10+'0');
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	return 0;
}
