#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//#define int LL
#define For(i,t,n) for(int i=t;i<=n;++i)
#define foR(i,t,n) for(int i=t;i>=n;--i)
#define isdigit(c) (c>=48&&c<=57)
#define gc getchar
void read(int& x){
	x=0;int c=gc(),f=1;
	while(!isdigit(c)){if(c=='-')f=-1;c=gc();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=gc();}
	x*=f;
}
void write(int x){
	int stk[128],top=0;
	if(x<0) putchar('-'),x=-x;
	do{stk[++top]=x%10;x/=10;}while(x);
	while(top)putchar(stk[top--]|48);
}

const int MAXN=1e5+5;

int c1,c2;
char s1[5],s2[5];
bool f1,f2,f3,f4;

bool chk1(char a,char b){
	bool aa=(a>='A'&&a<='C');
	bool bb=(b>='A'&&b<='C');
	return (1-(aa^bb));
}
bool chk2(char a,char b){
	if(a>b) swap(a,b);
	if(a=='A'&&b=='B') return 1;
	if(a=='B'&&b=='C') return 1;
	if(a=='D'&&b=='F') return 1;
	return 0;
}

void solve(){
	read(c1); scanf("%s",s1);
	read(c2); scanf("%s",s2);
	if(c1==c2){
		f1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			f2=1;
			if(chk1(s1[2],s2[2])){
				f3=1;
				if(chk2(s1[2],s2[2])){
					f4=1;
				}
			}
		}
	}
	putchar(f1|48);
	putchar(f2|48);
	putchar(f3|48);
	putchar(f4|48);
}

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out", "w", stdout);
	solve();
	return 0;
}
