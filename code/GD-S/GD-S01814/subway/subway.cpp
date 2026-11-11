#include<iostream>
#include<queue>
using namespace std;
#define int long long
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x==0)return;
	write(x/10);
	putchar(x%10+'0');
}
int n,m,d,q;
struct subway{
	deque<int> t;
	deque<int> a;
	int sum;
}k[500005];
int w[500005];
int ans,tol;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
		tol+=w[i];
	}
	for(int i=1;i<=n;i++){
		k[i].sum=read();
		for(int i=1;i<=k[i].sum;i++){
			k[i].a.push_back(read());
			k[i].t.push_back(read());
		}	 
	}
	while(q--){
		ans=0;
		int l,r;l=read();r=read();
		for(int i=1;i<=n;i++){
			for(auto j:k[i].t)
				ans+=j;
				ans+=w[i]; 
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
