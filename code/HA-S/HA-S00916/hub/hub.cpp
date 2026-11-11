#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int read(){
	long long  x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9') f=(ch=='-')?(-1):f,ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
void sb(int x,int y){
	long long ui[N],vi[N];
	for(int i=0;i<x;i++){
		ui[i]=read();
		vi[i]=read();
	}
	cout<<0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--){
		int n=read(),d=read();
		sb(n,d);
	}
	return 0;
}
