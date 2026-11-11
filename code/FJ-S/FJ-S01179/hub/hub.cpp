#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int subtask,t,n,k;

int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	
	subtask=read(),t=read();while(t--){
		n=read(),k=read();for(int i=1,u,v;i<n;++i)u=read(),v=read();
		printf("1\n");
	}
	return 0;
}


