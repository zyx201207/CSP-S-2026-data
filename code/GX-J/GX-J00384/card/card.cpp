#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
inline void print(int x){
	stack<char> s;
	do{
		s.push(x%10+'0');
		x/=10;
	}while(x);
	while(!s.empty()){
		putchar(s.top());
		s.pop();
	}
	putchar(' ');
}
const int N=5e5+10,M=3e5+10;
int a[N];
int cnt[N];
stack<int> s;
bool in[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	srand(time(0));
	int n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	if(n<=1e5){
		for(int i=1;i<n;++i){
			for(int j=i;j<=n;++j){
				if(!in[a[i]])s.push(a[i]);
				else{
					while(s.top()!=a[i]){
						in[s.top()]=0;
						s.pop();
					}
				}
			}
			for(int j=1;j<=m;++j){
				if(in[j])++cnt[j];
				in[j]=0;
			}
			s=stack<int>();
		}
		for(int i=1;i<=m;++i)print(cnt[i]);
	}else for(int i=1;i<=m;++i)print(rand());
	return 0;
}
