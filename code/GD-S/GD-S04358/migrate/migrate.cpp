#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+7;

void inpput(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}

inline ll read(){
	ll r=1;
	ll w=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')r*=-1;
		c=getchar();
	}
	
	while(c>='0'&&c<='9'){
		w=w*10+c-'0';
		c=getchar();
	}
	return r*w;
} 

int c,t;

int n;
ll d;

ll x[N];

ll ans;
ll cnt[N];

int main(){
	 
	inpput();
	
	c=read(),t=read();
	
	ll dis,num,l;
	
	while(t--){
		n=read();d=read();
		ans=0;
		
		
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		
		if(c==11||c==12){
			dis=x[2]-x[1];
			if(d<2*dis){
				printf("0\n");
			}else{
				num=d/dis;
				
				l=num*2-1;
				
				printf("%d\n",max(0ll,n-l));
			}
		}
		
	}
	
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
4 6 2
-4 -3 -2 -1 3 6

*/
 
