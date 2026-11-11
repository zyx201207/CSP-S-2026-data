#include<bits/stdc++.h>
using namespace std;
int c,T,n,m,a,b;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}return x*f;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n-1;i++)a=read(),b=read();
		cout<<n/m+1<<endl;
	}
	return 0;
}  
