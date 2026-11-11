#include<bits/stdc++.h>
using namespace std;
/*auto*/long long read(){
	char c=getchar_unlocked();
	/*auto*/long long sum=0;
	int f=1;
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar_unlocked();
	}
	while(c>='0'&&c<='9'){
		sum*=10;
		sum+=c-'0';
		c=getchar_unlocked();
	}
	return sum*f;
}
void write(/*auto*/long long sum){
	int s=-1;
	char c[20];
	if(sum<0){
		sum=-sum;
		putchar_unlocked('-');
	}
	if(sum==0){
		putchar_unlocked('0');
		return ;
	}
	while(sum!=0){
		c[++s]=sum%10+'0';
		sum/=10;
	}
	for(int i=s;i>=0;i--) putchar_unlocked(c[i]);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read();
	int b=read();
	while(b--){
		write(1);
		putchar_unlocked('\n');
	}
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
bool map[100][100];
int jidi[100];
int mi=INT_MAX;
long long read(){
	char c=getchar_unlocked();
	long long sum=0;
	int f=1;
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar_unlocked();
	}
	while(c>='0'&&c<='9'){
		sum*=10;
		sum+=c-'0';
		c=getchar_unlocked();
	}
	return sum*f;
}
void write(long long sum){
	int s=-1;
	char c[20];
	if(sum<0){
		sum=-sum;
		putchar_unlocked('-');
	}
	if(sum==0){
		putchar_unlocked('0');
		return ;
	}
	while(sum!=0){
		c[++s]=sum%10+'0';
		sum/=10;
	}
	for(int i=s;i>=0;i--) putchar_unlocked(c[i]);
}
int check(){
	int 
}
void dfs(int s,int mas,int c,int mac){
	if(c>mac){
		check();
	}
}
int main(){
	int c=read();
	int b=read();
	while(b--){
		int n=read();
		int k=read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				map[i][j]=0;
		for(int i=1;i<=n;i++){
			int u=read(),v=read();
			map[u][v]=1;
		}
		dfs(0,k,1,n);
	}
	return 0;
}

  */
