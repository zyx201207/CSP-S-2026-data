#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
int c,T,n;
long long d,x[N];
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch>'9' || ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		bool flag=true;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			x[i]=read();
			if(i>=3)
				if((x[i]-x[i-1])!=(x[i-1]-x[i-2]))
					flag=false;
		}
		if((c==11 || c==12) || flag){
			if(x[n]-x[n-1]<=d)
				printf("%d\n",n-3);
			else
				printf("0\n");
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2
*/
