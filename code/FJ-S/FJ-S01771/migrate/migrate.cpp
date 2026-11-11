#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
const int N=2e6+10;

int T;
int n,d;
int a[N];
int lst[N],nxt[N];

int F(int L,int R){
	if(L==R)return 0;
	int ans=0;
	for(int l=L;l<=R;l++){
		for(int r=l+1;r<=R;r++){
			int i=l;
			int tmp=0;
			while(i<r){
				i=min(r,nxt[i]);
				if(i==l||i==r)continue;
				if(i-1>l){
					if(nxt[i-1]>=min(nxt[i],r))tmp++;
					if(max(lst[i-1],l)<lst[i])tmp++;
				}
				if(i-2>l){
					if(nxt[i-2]>=min(nxt[i],r))tmp++;
					if(max(lst[i-2],l)<lst[i])tmp++;
				}
//				int y=lst[min(r,nxt[i])];
//				if(y!=i&&max(lst[y],l)==lst[i])tmp++;
			}
			if(tmp==1){
//				cout<<"okk "<<l<<' '<<r<<'\n';
				ans++;
			}
		}
	}
//	cout<<"F "<<L<<' '<<R<<' '<<ans<<'\n';
	return ans;
}

void clear(){
	for(int i=1;i<=n;i++){
		lst[i]=nxt[i]=0;
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read();
	T=read();
	while(T--){
		clear();
		n=read(),d=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++){
			lst[i]=lower_bound(a+1,a+i+1,a[i]-d)-a;
			nxt[i]=upper_bound(a+i,a+n+1,a[i]+d)-a-1;
//			cout<<i<<' '<<lst[i]<<' '<<nxt[i]<<'\n';
		}
		int L=0,R=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(lst[i]==i)L=i;
			if(nxt[i]==i)R=i;
			if(L&&R){
				ans+=F(L,R);
				L=0,R=0;
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

1
10 3
0 3 6 7 8 9 10 13 16 19

0 1
5 3
-3 0 2 3 4
*/