#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);	
	cin>>c>>t;
	while(t--){
		n=read(),k=read();
		for(int i=1;i<n;i++){
			u=read();v=read();
		}
		cout<<(n+1)/8-(k/4-1)<<endl;
	}
	return 0;
}
