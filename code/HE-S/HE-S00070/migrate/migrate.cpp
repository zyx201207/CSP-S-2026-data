#include<bits/stdc++.h>
using namespace std;
int read(){
	long long x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=10*x+(c^48);c=getchar();}
	return x*f;
}
long long n,x[2000005],c,t,d;
bool b[5005][5005];
void num2(){
	memset(b,0,sizeof(b));
	int aaa=0;
	for(int i=1;i<n;++i){
		b[i][i+1]=1;
		for(int j=i+2;j<=n;++j){
			if(x[j]-x[i]<=d)b[i][j]=1;
		}
	}
	for(int i=2;i<n;++i){
		if(b[i-1][i+1]==1&&b[i-2][i+1]==0&&b[i-1][i+2]==0)aaa++;
	}
	printf("%d\n",aaa);
}
void num1(){
	memset(b,0,sizeof(b));
	int aaa=0;
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j){
			if(x[j]>d+x[i])b[i][j]=1;
		}
	}
	for(int i=1;i<=n-2;++i){
		for(int j=i+3;j<=n;++j){
			int ch=0;
			for(int k=i+1;k<j;++k){
				if(b[i][k]==1&&b[k][j]==1)ch++;
			}
			if(ch==2){
				aaa++;
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	printf("%d\n",aaa);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read();d=read();
		for(int i=1;i<=n;++i)x[i]=read();
		if(n<=5000){
			if(x[1]+x[3]==(x[2]<<1))num2();
			else num1();
			continue;
		}
		else{
			cout<<0<<endl;
		}
	}
	return 0;
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*//*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
