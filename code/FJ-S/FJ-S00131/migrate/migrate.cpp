#include<bits/stdc++.h>
using namespace std;
int read(){
	int w=0,f=1;
	char ch=getchar();
	while(ch>'9' or ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' and ch<='9'){
		w=(w<<3)+(w<<1)+(ch^48);
		ch=getchar();
	}
	return w*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}
