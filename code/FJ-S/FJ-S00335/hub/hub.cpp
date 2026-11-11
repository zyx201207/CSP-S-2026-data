//T4
#include<bits/stdc++.h>
using namespace std;
#define int long long

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}

void out(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)out(x/10);
	putchar(x%10+'0');
}
void write(int x){out(x);putchar(10);}
void wrote(int x){out(x);putchar(32);}

const int N=2e6+10;

int n,k;

//vector<int>g[N];

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int C=read();
	int T=read();
	while(T--){
		int n=read(),k=read();
		int m=(n-1)>>1;
		int dep=m+1;
		for(int i=1;i<n;i++){
			int u=read(),v=read();
//			g[u].push_back(v);
//			g[v].push_back(u);
		}
		if(k>=n)write(0);
		else{
			if(dep%2==1){
				if(k%2==1){
					if(dep-k>0)write((dep-k)/2+1);
					else write(1);
				}else{
					if(dep-k==1)write(1);
					else if(dep-k<1)write(1);
					else write((dep-k)/2+1);
				}
			}else{
				if(k%2==0){
					if(dep-k>0)write((dep-k)/2+1);
					else write(1);
				}else{
					if(dep-k==1)write(1);
					else if(dep-k<1)write(1);
					else write((dep-k)/2+1);
				}
			}
		}
	}
	
	return 0;
}

