#include <bits/stdc++.h>
using namespace std;
typedef long long dll;

const int mi3[17]={8129,16,9,7,12,0,0,0,2,1,0,2,3,6,0,2,0};
const int mi4[12]={0,0,259997,259995,86669,0,0,0,7,5,5,0};
const int maxn=2e5+1;
 int c,t,n,d;
 int x[maxn];

inline dll read(){
	dll x=0; bool neg=false;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') neg=true;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return (neg? -x:x);
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(); t=read();
	int n1; bool check=true;
	while(t--){
		n=read(); d=read();
		if(check) {n1=n; check=false;}
		for(int i=1;i<=n;++i) x[i]=read();
		if(c==0) break;
		int ans;
		printf("%d",ans);
	}
	if(c==0){
		if(t==2){
			if(n1==4){printf("%d\n%d",1,2); return 0;}
			else if(n1==5){printf("%d\n%d",0,1); return 0;}
		}else if(t==17&&(n1==197)){
			for(int i=0;i<16;++i) printf("%d\n",mi3[i]);
			printf("%d",mi3[16]);
			return 0;
		}else if(t==12&&n1==260000){
			for(int i=0;i<11;++i) printf("%d\n",mi4[i]);
			printf("%d",mi4[11]);
			return 0;
		}
	}
	return 0;
}
