#include<bits/stdc++.h>
#define ll long long 
using namespace std;
char buf[1<<20],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
template<typename T>
T read(){
	T k=0,f=1;
	int c=gc();
	for(;!isdigit(c);c=gc()) if(c=='-') f=-1;
	for(;isdigit(c);c=gc()) k=(k<<3)+(k<<1)+(c-'0');
	return k*f; 
}
template<typename T>
void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
const int N=5e5+5,M=3e5+5;
stack<int> s;
int a[N],ans[N];
bool b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n=read<int>(),m=read<int>();
	memset(ans,-1,sizeof(ans));
	bool x=1;
	a[0]=-1;
	for(int i=1;i<=n;i++){
		a[i]=read<int>();
		if(a[i]<a[i-1]) x=0;
		ans[a[i]]=i;
	}
	if(n==m) x=1;
	if(x){
		for(int i=1;i<=m;i++){
			write(ans[i]);
			putchar(' ');
		}
		return 0;
	}
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				while(s.top()!=a[j]) b[s.top()]=0,s.pop();
			}
			else {
				s.push(a[j]);
				b[a[j]]=1;
			}
		}
		while(!(s.empty())) ans[s.top()]++,s.pop();
	}
	for(int i=1;i<=m;i++){
		write(ans[i]);
		putchar(' ');
	} 
	return 0;
} 
